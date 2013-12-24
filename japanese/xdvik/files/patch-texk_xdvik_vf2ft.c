--- xdvik-22.40w/texk/xdvik/vf2ft.c.orig	2013-12-16 09:29:17.000000000 +0100
+++ xdvik-22.40w/texk/xdvik/vf2ft.c	2013-12-16 09:29:47.000000000 +0100
@@ -1278,7 +1278,6 @@
 
 static int fontsmax=0;
 
-#include <freetype/freetype.h>
 #include "vf2ft.h"
 
 int VF_Init(char *vfcap)
