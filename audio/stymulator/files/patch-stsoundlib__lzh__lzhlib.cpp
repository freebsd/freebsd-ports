--- ./stsoundlib/lzh/lzhlib.cpp.orig	2010-04-23 13:49:47.000000000 +0200
+++ ./stsoundlib/lzh/lzhlib.cpp	2010-04-23 13:49:47.000000000 +0200
@@ -413,10 +413,10 @@
 
     decode_start ();
 
-	int origsize = dstSize;
+	uint origsize = dstSize;
     while (origsize != 0)
     {
-        int n = (uint) ((origsize > DICSIZ) ? DICSIZ : origsize);
+        uint n = (origsize > DICSIZ) ? DICSIZ : origsize;
         decode (n, outbuf);
 		if (with_error)
 			break;
