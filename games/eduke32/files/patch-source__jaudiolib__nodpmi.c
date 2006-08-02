--- ./source/jaudiolib/nodpmi.c.orig	Wed Aug  2 00:35:30 2006
+++ ./source/jaudiolib/nodpmi.c	Wed Aug  2 00:35:30 2006
@@ -0,0 +1,50 @@
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
+   module: NODPMI.C
+
+   Functions for faking DPMI calls.
+
+**********************************************************************/
+
+#include <stdlib.h>
+#include <string.h>
+#include "dpmi.h"
+
+#define TRUE  ( 1 == 1 )
+#define FALSE ( !TRUE )
+
+int DPMI_GetDOSMemory( void **ptr, int *descriptor, unsigned length )
+{
+   /* Lovely... */
+   
+   *ptr = (void *)malloc(length);
+   
+   *descriptor = (int) *ptr;
+   
+   return (descriptor == 0) ? DPMI_Error : DPMI_Ok;
+}
+
+int DPMI_FreeDOSMemory( int descriptor )
+{
+   free((void *)descriptor);
+   
+   return (descriptor == 0) ? DPMI_Error : DPMI_Ok;
+}
