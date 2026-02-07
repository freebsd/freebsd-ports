--- ./src/text.c.orig	1997-12-11 00:27:49.000000000 +0100
+++ ./src/text.c	2014-01-19 19:19:52.000000000 +0100
@@ -7,6 +7,8 @@
 
 #include <X11/Xlib.h>
 #include "text.h"
+#include <stdio.h>
+#include <string.h>
 
 int FontHeight(XFontStruct *font_struct)
 {
