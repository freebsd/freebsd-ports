--- acpica-unix-20030523/osunixxf.c.orig	Sat May 24 09:11:02 2003
+++ acpica-unix-20030523/osunixxf.c	Thu Jun 12 17:03:26 2003
@@ -815,7 +815,7 @@
     UINT32                  milliseconds)
 {
 
-    sleep ((seconds * 1000) + milliseconds);
+    usleep ((seconds * 1000) + milliseconds);
     return;
 }
 
