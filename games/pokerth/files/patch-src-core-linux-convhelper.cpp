--- src/core/linux/convhelper.cpp.orig	2008-01-20 13:32:07.000000000 +0100
+++ src/core/linux/convhelper.cpp	2008-01-20 12:56:03.000000000 +0100
@@ -39,7 +39,7 @@
 #ifdef __APPLE__
 	const char *inbuf = inStr.data();
 #else
-	char *inbuf = const_cast<char *>(inStr.data());
+	const char *inbuf = const_cast<char *>(inStr.data());
 #endif
 
 	const size_t c_outsize = insize * 6; // max size of utf-8 char is 6 per input char
@@ -74,7 +74,7 @@
 #ifdef __APPLE__
 	const char *inbuf = inStr.data();
 #else
-	char *inbuf = const_cast<char *>(inStr.data());
+	const char *inbuf = const_cast<char *>(inStr.data());
 #endif
 
 	const size_t c_outsize = insize;
