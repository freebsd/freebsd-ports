--- src/osgPlugins/freetype/FreeTypeFont.cpp.orig	2013-12-24 19:29:26.000000000 +0100
+++ src/osgPlugins/freetype/FreeTypeFont.cpp	2013-12-24 19:30:24.000000000 +0100
@@ -14,8 +14,9 @@
 #include "FreeTypeFont.h"
 #include "FreeTypeLibrary.h"
 
-#include <freetype/ftoutln.h>
-#include <freetype/ftbbox.h>
+#include <ft2build.h>
+#include FT_OUTLINE_H
+#include FT_BBOX_H
 
 #include <osg/Notify>
 #include <osg/io_utils>
