--- osunixxf.c.orig	Mon May 20 23:27:31 2002
+++ osunixxf.c	Fri Jun  7 22:23:11 2002
@@ -728,7 +728,7 @@
     UINT32                  milliseconds)
 {
 
-    sleep ((seconds * 1000) + milliseconds);
+    usleep ((seconds * 1000) + milliseconds);
     return;
 }
 
