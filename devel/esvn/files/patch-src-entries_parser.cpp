--- src/entries_parser.cpp.orig	Wed Apr 27 00:26:22 2005
+++ src/entries_parser.cpp	Mon Jul  4 16:24:56 2005
@@ -283,7 +283,7 @@
 
 	time_t utc_time;
 
-#if defined(FreeBSD)
+#if defined(__FreeBSD__)
 
 	// BSD has inverse of gmtime()
 	utc_time = timegm(&m);
