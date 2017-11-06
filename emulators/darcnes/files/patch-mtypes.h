--- mtypes.h.orig	1999-08-07 16:19:37 UTC
+++ mtypes.h
@@ -9,6 +9,8 @@
 
 /* $Id: mtypes.h,v 1.2 1999/08/07 16:19:37 nyef Exp $ */
 
+#include "endian.h"
+
 typedef unsigned char byte;
 typedef unsigned short word;
 typedef signed char offset;
