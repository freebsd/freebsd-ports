
$FreeBSD$

--- ../include/os.h.orig	Fri Feb  9 02:18:26 2001
+++ ../include/os.h	Fri Feb  9 12:23:54 2001
@@ -21,7 +21,7 @@
 
 #include <limits.h>
 
-#ifdef __linux__
+#if defined(__linux__) && defined(__FreeBSD__)
 # include <paths.h>
 #endif
 
@@ -58,7 +58,7 @@
 # define _PATH_DEVNULL		"/dev/null"
 #endif
 
-#ifndef _AIX
+#if !defined(_AIX) && !defined(__FreeBSD__)
 # ifndef _PATH_MAILDIR
 #  define _PATH_MAILDIR		"/var/spool/mail"
 # endif
