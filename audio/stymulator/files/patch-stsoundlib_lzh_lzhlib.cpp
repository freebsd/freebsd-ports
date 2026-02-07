--- stsoundlib/lzh/lzhlib.cpp.orig	2016-07-26 16:04:42 UTC
+++ stsoundlib/lzh/lzhlib.cpp
@@ -413,10 +413,10 @@ bool	CLzhDepacker::LzUnpack(void *pSrc,i
 
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
