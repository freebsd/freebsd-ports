--- MultiPlay.cpp.orig	Tue Nov 11 16:12:35 2003
+++ MultiPlay.cpp	Tue Nov 11 16:10:24 2003
@@ -35,7 +35,7 @@
 
 #if defined(WIN32) || defined(__FreeBSD__)
 
-typedef int socklen_t;		/* mimic Penguin's typedef */
+//typedef int socklen_t;		/* mimic Penguin's typedef */
 
 #else	/* ! WIN32 */
 
