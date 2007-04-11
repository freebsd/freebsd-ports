--- lib/gis/intr_char.c	Thu Feb  9 04:08:56 2006
+++ lib/gis/intr_char.c	Mon Mar 26 19:27:22 2007
@@ -2,7 +2,11 @@
 
 #include <grass/config.h>
 #ifndef __MINGW32__
-#ifdef HAVE_TERMIO_H
+#if defined(HAVE_TERMIOS_H)
+# include <termios.h>
+# define TYPE termios
+# define C c_cc[VINTR]
+#elif defined(HAVE_TERMIO_H)
 # include <termio.h>
 # define TYPE termio
 # define C c_cc[VINTR]
@@ -32,7 +36,11 @@
 #ifndef __MINGW32__    
     struct TYPE buf;
 
+#ifdef HAVE_TERMIOS_H
+    tcgetattr (2, &buf);
+#else
     ioctl (2, GET, &buf);
+#endif
     c = buf.C;
 #endif    
     return c;
