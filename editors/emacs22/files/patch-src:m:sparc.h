--- src/m/sparc.h.orig	Thu Sep 12 02:25:09 2002
+++ src/m/sparc.h	Thu Sep 12 12:33:36 2002
@@ -89,7 +89,7 @@
 #define PURESIZE 130000
 #endif
 
-#if !defined (__NetBSD__) && !defined (__linux__) && !defined (__OpenBSD__)
+#if !defined (__NetBSD__) && !defined (__linux__) && !defined (__OpenBSD__) && !defined(__FreeBSD__)
 /* This really belongs in s/sun.h.  */
 
 /* Say that the text segment of a.out includes the header;
