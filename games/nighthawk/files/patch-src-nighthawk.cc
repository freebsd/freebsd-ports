--- src/nighthawk.cc.orig	Wed Apr  4 14:23:09 2001
+++ src/nighthawk.cc	Wed Apr  4 14:23:19 2001
@@ -116,7 +116,7 @@
   FILE *fp;
 
   if((fp = fopen(filename,mode)) != NULL)
-    flock(fp->_fileno,LOCK_EX);
+    flock(fileno(fp),LOCK_EX);
   return fp;
 }
 
