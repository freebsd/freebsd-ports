--- src/configuration.c.orig	Mon Apr 28 06:56:46 2003
+++ src/configuration.c	Thu May  8 23:27:11 2003
@@ -5,6 +5,8 @@
 #ifdef _WIN32
 #include <winsock.h>
 #else
+#include <sys/types.h>
+#include <sys/time.h>
 #include <sys/socket.h>
 #endif
 
@@ -51,7 +53,7 @@
 	gfx.bpp = 16;
     bman.fieldsize.x = 25;
     bman.fieldsize.y = 17;
-    sprintf (bman.datapath, "data/bomberclone.gfx");
+    sprintf (bman.datapath, "@@LOCALBASE@@/share/bomberclone.gfx");
 };
 
 int
