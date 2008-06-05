--- ./src/ui/ui.c.orig	2008-05-22 00:23:37.000000000 +0400
+++ ./src/ui/ui.c	2008-06-04 22:36:27.000000000 +0400
@@ -1243,7 +1243,7 @@
 #ifdef USE_LOCALEPATH
     localepath)
 #else
-    "/usr/share/locale")
+    PREFIX "/share/locale")
 #endif
 #ifdef DEBUG
     )
