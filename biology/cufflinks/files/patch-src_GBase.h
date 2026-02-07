--- src/GBase.h.orig	2019-07-06 16:28:01 UTC
+++ src/GBase.h
@@ -1,6 +1,6 @@
 #ifndef G_BASE_DEFINED
 #define G_BASE_DEFINED
-#ifndef _POSIX_SOURCE
+#if !defined(_POSIX_SOURCE) && !defined(__FreeBSD__)
 //mostly for MinGW
 #define _POSIX_SOURCE
 #endif
@@ -71,7 +71,7 @@ typedef int16_t int16;
 typedef uint16_t uint16;
 
 typedef unsigned char uchar;
-typedef unsigned char byte;
+typedef unsigned char bytex;
 
 #ifndef MAXUINT
 #define MAXUINT ((unsigned int)-1)
