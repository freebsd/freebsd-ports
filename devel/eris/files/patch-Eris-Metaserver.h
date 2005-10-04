--- Eris/Metaserver.h.orig	Tue Oct  4 17:40:26 2005
+++ Eris/Metaserver.h	Tue Oct  4 17:40:52 2005
@@ -11,7 +11,7 @@
 #include <sigc++/object.h>
 #include <sigc++/signal.h>
 
-#ifndef __WIN32__
+#if !defined(__WIN32__) && defined(HAVE_STDINT_H)
 // pull in uint32_t on POSIX - is this generic?!
 #include <stdint.h>
 #else
