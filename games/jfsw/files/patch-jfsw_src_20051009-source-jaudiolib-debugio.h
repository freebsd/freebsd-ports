--- jfsw_src_20051009/source/jaudiolib/debugio.h.orig	1970-01-01 01:00:00.000000000 +0100
+++ jfsw_src_20051009/source/jaudiolib/debugio.h	2005-10-10 15:02:08.000000000 +0200
@@ -0,0 +1,30 @@
+/*
+Copyright (C) 1994-1995 Apogee Software, Ltd.
+
+This program is free software; you can redistribute it and/or
+modify it under the terms of the GNU General Public License
+as published by the Free Software Foundation; either version 2
+of the License, or (at your option) any later version.
+
+This program is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
+
+See the GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with this program; if not, write to the Free Software
+Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
+
+*/
+#ifndef __DEBUGIO_H
+#define __DEBUGIO_H
+
+void DB_SetXY( int x, int y );
+void DB_PutChar( char ch );
+int  DB_PrintString( char *string );
+int  DB_PrintNum( int number );
+int  DB_PrintUnsigned( unsigned long number, int radix );
+int  DB_printf( char *fmt, ... );
+
+#endif
