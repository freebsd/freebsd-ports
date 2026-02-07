--- ./include/zlibpng/zconf.h.orig	Tue May 23 20:05:59 2006
+++ ./include/zlibpng/zconf.h	Tue May 23 20:06:00 2006
@@ -254,7 +254,7 @@
 #if !defined(__MACTYPES__)
 typedef unsigned char  Byte;  /* 8 bits */
 #endif
-#if !defined(__linux__) && !defined(__FreeBSD__)
+#ifndef __unix__
 typedef unsigned int   uInt;  /* 16 bits or more */
 typedef unsigned long  uLong; /* 32 bits or more */
 #endif
