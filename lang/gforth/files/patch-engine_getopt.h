--- engine/getopt.h.orig	2013-10-11 21:31:28 UTC
+++ engine/getopt.h
@@ -95,7 +95,7 @@ struct option
 #define optional_argument	2
 
 #if __STDC__
-#if defined(__GNU_LIBRARY__)
+#if defined(__GNU_LIBRARY__) || defined(__FreeBSD__)
 /* Many other libraries have conflicting prototypes for getopt, with
    differences in the consts, in stdlib.h.  To avoid compilation
    errors, only prototype getopt for the GNU C library.  */
