--- src/makeint.h.orig	2020-01-19 20:32:59 UTC
+++ src/makeint.h
@@ -116,7 +116,6 @@ extern int errno;
 
 /* Some systems define _POSIX_VERSION but are not really POSIX.1.  */
 #if (defined (butterfly) || defined (__arm) || (defined (__mips) && defined (_SYSTYPE_SVR3)) || (defined (sequent) && defined (i386)))
-# undef POSIX
 #endif
 
 #if !defined (POSIX) && defined (_AIX) && defined (_POSIX_SOURCE)
