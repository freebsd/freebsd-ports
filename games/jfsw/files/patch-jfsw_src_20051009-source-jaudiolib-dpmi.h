--- jfsw_src_20051009/source/jaudiolib/dpmi.h.orig	1970-01-01 01:00:00.000000000 +0100
+++ jfsw_src_20051009/source/jaudiolib/dpmi.h	2005-10-10 15:02:08.000000000 +0200
@@ -0,0 +1,43 @@
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
+/**********************************************************************
+   module: DPMI.H
+
+   author: James R. Dose
+   date:   March 31, 1994
+
+   Inline functions for performing DPMI calls.
+
+   (c) Copyright 1994 James R. Dose.  All Rights Reserved.
+**********************************************************************/
+
+#ifndef __DPMI_H
+#define __DPMI_H
+
+enum DPMI_Errors
+   {
+   DPMI_Warning = -2,
+   DPMI_Error   = -1,
+   DPMI_Ok      = 0
+   };
+
+int  DPMI_GetDOSMemory( void **ptr, int *descriptor, unsigned length );
+int  DPMI_FreeDOSMemory( int descriptor );
+#endif
