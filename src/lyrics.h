/***************************************************************************
 *   Copyright (C) 2008-2010 by Andrzej Rybczak                            *
 *   electricityispower@gmail.com                                          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef _LYRICS_H
#define _LYRICS_H

#include "ncmpcpp.h"
#include "mpdpp.h"
#include "screen.h"

class Lyrics : public Screen<Scrollpad>
{
	public:
		Lyrics() : itsScrollBegin(0) { }
		~Lyrics() { }
		
		virtual void Resize();
		virtual void SwitchTo();
		
		virtual std::basic_string<my_char_t> Title();
		
		virtual void Update();
		
		virtual void EnterPressed() { }
		virtual void SpacePressed();
		
		virtual bool allowsSelection() { return false; }
		
		virtual List *GetList() { return 0; }
		
		void Edit();
		void Save(const std::string &lyrics);
		void FetchAgain();
		
		static bool Reload;
		
	protected:
		virtual void Init();
		
	private:
		std::string itsFilenamePath;
		
		static const std::string Folder;
		
#		ifdef HAVE_CURL_CURL_H
		static void *Get(void *);
		
		void Take();
		
		static bool Ready;
		
		static pthread_t *Downloader;
		
#		endif // HAVE_CURL_CURL_H
		
		size_t itsScrollBegin;
		MPD::Song itsSong;
};

extern Lyrics *myLyrics;

#endif

