--- lockservice/LockParse.cpp.orig	Sun Feb 20 17:42:22 2005
+++ lockservice/LockParse.cpp	Sun Feb 20 17:42:40 2005
@@ -155,7 +155,8 @@
 #ifdef _WIN32
 	this_clock = GetTickCount();
 #else
-	this_clock = times(NULL);
+	struct tms tms_buf;
+	this_clock = times(&tms_buf);
 #endif
 
 	if(this_clock<last_clock.clock)
