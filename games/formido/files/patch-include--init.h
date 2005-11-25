--- include/init.h.orig	Fri Nov  7 21:59:07 2003
+++ include/init.h	Sat Nov 19 19:39:18 2005
@@ -45,7 +45,7 @@
 
 #define DAT(x) (add_prefix(x, DATA_DIR))
 #define HISCORE(x) (add_prefix(x, HISCORE_DIR))
-#define CONFIG(x) (add_prefix(x, CONFIG_DIR))
+#define CONFIG(x) (add_prefix(x, getenv("HOME")))
 
 
 // Initialize SDL
