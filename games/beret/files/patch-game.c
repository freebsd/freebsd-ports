--- game.c.orig	2017-04-09 23:30:52 UTC
+++ game.c
@@ -94,7 +94,7 @@
 #elif defined __WIN32__
 #define RESOURCE_PATH ""
 #else
-#define RESOURCE_PATH ""
+#define RESOURCE_PATH "%%PREFIX%%/share/beret/"
 #endif
 #endif
 
