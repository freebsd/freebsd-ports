--- dtrans/source/X11/X11_selection.cxx.orig	Sat Jul 20 23:18:03 2002
+++ dtrans/source/X11/X11_selection.cxx	Sat Jul 20 23:18:05 2002
@@ -65,7 +65,7 @@
 #include <X11/keysym.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
-#if defined(LINUX) || defined(NETBSD)
+#if defined(LINUX) || defined(NETBSD) || defined (FREEBSD)
 #include <sys/poll.h>
 #else
 #include <poll.h>
@@ -175,6 +175,7 @@
 	{ 0, "text/plain;charset=ksc5601.1992-0", "KSC5601.1992-0", 8 },
 	// eastern european encodings
 	{ 0, "text/plain;charset=koi8-r", "KOI8-R", 8 },
+	{ 0, "text/plain;charset=koi8-u", "KOI8-U", 8 },
 	// String (== iso8859-1)
 	{ XA_STRING, "text/plain;charset=string", "STRING", 8 },
     // special for compound text
