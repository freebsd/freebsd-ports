--- src/md5.cpp.orig	2016-02-22 02:11:13 UTC
+++ src/md5.cpp
@@ -166,7 +166,7 @@ MD5Transform(DWORD buf[4], const DWORD in[16])
 void
 MD5Transform(DWORD buf[4], const DWORD in[16])
 {
-	register DWORD a, b, c, d;
+	DWORD a, b, c, d;
 
 	a = buf[0];
 	b = buf[1];
