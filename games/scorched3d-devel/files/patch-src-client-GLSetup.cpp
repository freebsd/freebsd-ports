--- src/client/GLSetup.cpp.orig	Wed Jul 30 17:41:24 2003
+++ src/client/GLSetup.cpp	Sun Aug  3 09:07:11 2003
@@ -25,7 +25,7 @@
 
 #include <client/GLSetup.h>
 #include <GLEXT/GLStateExtension.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 void GLSetup::setup()
 {
