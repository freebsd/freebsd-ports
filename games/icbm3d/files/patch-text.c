--- ./text.c.orig	1998-07-29 23:25:59.000000000 +0200
+++ ./text.c	2013-12-24 08:28:45.000000000 +0100
@@ -7,6 +7,7 @@
 
 #include <X11/Xlib.h>
 #include "text.h"
+#include <string.h>
 
 int FontHeight(XFontStruct *font_struct)
 {
