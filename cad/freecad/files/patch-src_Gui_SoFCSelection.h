--- ./src/Gui/SoFCSelection.h.orig	2023-01-21 22:41:40.507560000 +0100
+++ ./src/Gui/SoFCSelection.h	2023-01-21 22:42:27.657720000 +0100
@@ -35,6 +35,8 @@
 # include <GL/gl.h>
 # endif
 
+#include <array>
+
 #include <Inventor/elements/SoLazyElement.h>
 #include <Inventor/fields/SoSFBool.h>
 #include <Inventor/fields/SoSFColor.h>
