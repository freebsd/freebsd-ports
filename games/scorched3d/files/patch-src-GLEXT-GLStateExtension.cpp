--- src/GLEXT/GLStateExtension.cpp.orig	Wed Jul 30 17:41:26 2003
+++ src/GLEXT/GLStateExtension.cpp	Sun Aug  3 09:07:13 2003
@@ -20,7 +20,7 @@
 
 
 #include <GLEXT/GLStateExtension.h>
-#include <SDL/SDL.h>
+#include <SDL11/SDL.h>
 #include <string.h>
 
 bool GLStateExtension::noExtensions_ = false;
