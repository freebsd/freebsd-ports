--- ../_imagingft.c.orig	Mon Mar 22 23:27:33 2004
+++ ../_imagingft.c	Mon Mar 22 23:28:03 2004
@@ -15,7 +15,8 @@
 #include "Python.h"
 #include "Imaging.h"
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #if PY_VERSION_HEX < 0x01060000
 #define PyObject_DEL(op) PyMem_DEL((op))
