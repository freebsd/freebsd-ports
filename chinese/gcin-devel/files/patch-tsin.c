--- tsin.c.orig	Sat Jul 24 19:33:14 2004
+++ tsin.c	Sat Jul 24 19:34:11 2004
@@ -722,7 +722,7 @@
   selidx[0]=tmp;
 
   if ((fp=fopen(tsidxfname,"r+"))==NULL) {
-    error("%s modify err", tsidxfname);
+    p_err("%s modify err", tsidxfname);
     return;
   }
 
