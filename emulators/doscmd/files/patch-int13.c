--- int13.c.orig	2011-08-26 16:48:21 UTC
+++ int13.c
@@ -487,7 +487,7 @@ diread(struct diskinfo *di, regcontext_t
     off_t res;
 
     int drive = di - diskinfo;
-    di->multi = -1;
+    di->multi = 3;
 
     if (drive > 1) {
 	drive -= 2;
@@ -536,7 +536,7 @@ diwrite(struct diskinfo *di, regcontext_
 {
     off_t res;
     int drive = di - diskinfo;
-    di->multi = -1;
+    di->multi = 3;
 
     if (drive > 1) {
 	drive -= 2;
