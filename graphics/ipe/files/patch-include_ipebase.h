--- include/ipebase.h.orig	2016-01-24 11:16:26 UTC
+++ include/ipebase.h
@@ -51,9 +51,9 @@
 
 using uchar = unsigned char;
 
-#if defined(WIN32) || defined(__APPLE__)
+// #if defined(WIN32) || defined(__APPLE__)
 using uint = unsigned int;
-#endif
+// #endif
 
 #ifdef WIN32
 #define IPESEP ('\\')
