--- tools/SigHandler.c.orig	Fri Oct 25 12:04:13 2002
+++ tools/SigHandler.c	Fri Oct 25 12:04:33 2002
@@ -222,7 +222,7 @@
   int  index;
   int  pid;
 
-#if defined(_POSIX_SOURCE) || defined(_INCLUDE_POSIX_SOURCE)
+#if defined(_POSIX_SOURCE) || defined(_INCLUDE_POSIX_SOURCE) || defined(__FreeBSD__)
   int  status;
 #else
   union wait  status;
