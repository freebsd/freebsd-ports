--- gtab.c.orig	Mon Aug 23 23:11:43 2004
+++ gtab.c	Tue Aug 24 07:16:39 2004
@@ -439,7 +439,7 @@
   len = ofs1 - ofs;
 
   if (len > 128 || len <= 0) {
-    error("phrae error %d\n", len);
+    dbg("phrae error %d\n", len);
     strcpy(tt,"err");
     return;
   }
