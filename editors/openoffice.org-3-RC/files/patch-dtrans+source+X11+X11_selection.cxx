--- ../dtrans/source/X11/X11_selection.cxx.orig	Sat Jul 20 23:18:03 2002
+++ ../dtrans/source/X11/X11_selection.cxx	Sat Jul 20 23:18:05 2002
@@ -65,7 +65,7 @@
 #include <X11/keysym.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
-#if defined(LINUX) || defined(NETBSD)
+#if defined(LINUX) || defined(NETBSD) || defined (FREEBSD)
 #include <sys/poll.h>
 #else
 #include <poll.h>
