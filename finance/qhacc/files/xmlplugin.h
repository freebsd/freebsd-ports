/************************* * * * * * * * * * * * * ***************************
    Copyright (c) 1999-2003 Ryan Bobko
                       ryan@ostrich-emulators.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     
************************** * * * * * * * * * * * * **************************/

#ifndef XMLIMPORTER_H
#define XMLIMPORTER_H

#include "localfileplugin.h"

#include <stdlib.h>
#include <tree.h>
#include <xmlmemory.h>
#include <parser.h>

class XMLDBPlugin : public LocalFileDBPlugin {
 public:
	XMLDBPlugin();
	virtual ~XMLDBPlugin();

	virtual bool load( QHacc * eng, const QString& home, QString& error );
	virtual bool save( const QString&, bool, QString& );

	virtual QString description() const;
	static QString sdescription();

	virtual QString understands() const; // what QHACC_HOME keywords do I know?
	static QString sunderstands(); // what QHACC_HOME keywords do I know?

 protected:
	void writeTable( QHaccResultSet& data, const char ** lbls, uint lblcnt,
									 xmlDocPtr tree, xmlNsPtr ns, const QString& label ) const;
	void readTable( QHaccResultSet& data, const char ** lbls,
									uint lblcnt, xmlNodePtr cur, xmlDocPtr doc, 
									const QString& label ) const;
};

#endif
