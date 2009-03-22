--- source/blender/ftfont/intern/FTF_TTFont.h.orig	2009-03-20 23:55:22.000000000 +0100
+++ source/blender/ftfont/intern/FTF_TTFont.h	2009-03-21 00:22:43.000000000 +0100
@@ -34,8 +34,9 @@
 #ifndef __FTF_TRUETYPE_FONT_H
 #define __FTF_TRUETYPE_FONT_H
 
-#include "FTGLPixmapFont.h"
-#include "FTGLTextureFont.h"
+#include <GL/gl.h>
+#include <GL/glu.h>
+#include <ftgl.h>
 
 #include <stdio.h>
 //#include <iconv.h>
