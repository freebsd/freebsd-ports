--- ../dtrans/source/X11/X11_selection.cxx.orig	Wed Jul 31 22:43:56 2002
+++ ../dtrans/source/X11/X11_selection.cxx	Fri Oct 18 20:16:37 2002
@@ -66,7 +66,7 @@
 #include <X11/keysym.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
-#ifdef LINUX
+#if defined(LINUX) || defined(NETBSD) || defined (FREEBSD)
 #include <sys/poll.h>
 #else
 #include <poll.h>
