--- Network.cpp.orig	Tue Nov 11 16:13:38 2003
+++ Network.cpp	Tue Nov 11 16:16:03 2003
@@ -38,7 +38,7 @@
 
 #if defined(WIN32) || defined(__FreeBSD__)
 
-typedef int socklen_t;		/* mimic Penguin's typedef */
+//typedef int socklen_t;		/* mimic Penguin's typedef */
 
 #else	/* ! WIN32 */
 
@@ -164,7 +164,7 @@
 
   char *b = buf;
   long millitm;
-  b = ReadLong( b, tb->time );
+  b = ReadLong( b, (long)tb->time );
   b = ReadLong( b, millitm );
   tb->millitm = (unsigned short)millitm;
 
