--- getopt.c.orig	2008-01-26 13:11:10.000000000 +0800
+++ getopt.c	2008-01-26 13:14:27.000000000 +0800
@@ -44,7 +44,7 @@
 
 #include <stdio.h>
 
-#ifdef __sparc__
+#if defined(__sparc) && !defined(__FreeBSD__)
 extern int fprintf( FILE *, const char *, ... );
 extern int strncmp( const char *, const char *, int n );
 #endif
