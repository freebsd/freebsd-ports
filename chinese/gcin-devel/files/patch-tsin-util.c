--- tsin-util.c.orig	Sat Jul 24 19:34:37 2004
+++ tsin-util.c	Sat Jul 24 19:34:55 2004
@@ -149,7 +149,7 @@
   for(;hashno<256;hashno++) hashidx[hashno]++;
 
   if ((fw=fopen(tsidxfname,"w"))==NULL) {
-    error("%s create err", tsidxfname);
+    p_err("%s create err", tsidxfname);
     return FALSE;
   }
 
