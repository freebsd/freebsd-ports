--- src/makeint.h.orig	2022-07-30 04:31:09 UTC
+++ src/makeint.h
@@ -113,11 +113,6 @@ extern int errno;
 # endif
 #endif
 
-/* Some systems define _POSIX_VERSION but are not really POSIX.1.  */
-#if (defined (butterfly) || defined (__arm) || (defined (__mips) && defined (_SYSTYPE_SVR3)) || (defined (sequent) && defined (i386)))
-# undef POSIX
-#endif
-
 #if !defined (POSIX) && defined (_AIX) && defined (_POSIX_SOURCE)
 # define POSIX 1
 #endif
