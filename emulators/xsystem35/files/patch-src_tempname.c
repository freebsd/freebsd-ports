--- src/tempname.c.orig	Mon Nov 10 00:06:13 2003
+++ src/tempname.c	Sun Aug 15 02:36:09 2004
@@ -112,7 +112,7 @@
    uintmax_t is only 32 bits lose about 3.725 bits of randomness,
    which is better than not having mkstemp at all.  */
 #if !defined UINT64_MAX && !defined uint64_t
-# define uint64_t uintmax_t
+# define uint64_t u_int64_t
 #endif
 
 /* These are the characters used in temporary filenames.  */
