--- src/kmk/getopt.h.orig	2026-01-31 20:06:08 UTC
+++ src/kmk/getopt.h
@@ -97,7 +97,7 @@ struct option
 #define optional_argument	2
 
 #if defined (__STDC__) && __STDC__
-#ifdef __GNU_LIBRARY__
+#if defined (__GNU_LIBRARY__) || defined (__FreeBSD__)
 /* Many other libraries have conflicting prototypes for getopt, with
    differences in the consts, in stdlib.h.  To avoid compilation
    errors, only prototype getopt for the GNU C library.  */
