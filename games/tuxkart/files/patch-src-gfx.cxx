--- src/gfx.cxx.orig	2004-03-18 17:21:44.000000000 +0100
+++ src/gfx.cxx	2013-06-27 01:40:14.000000000 +0200
@@ -4,8 +4,10 @@
 #ifndef WIN32
 #include <unistd.h>
 #include <string.h>
+#if 0
 #include <sys/io.h>
-#include <sys/perm.h>                                                           
+#include <sys/perm.h>
+#endif
 #endif
 
 static unsigned int lastKeystroke = 0 ;
@@ -137,6 +139,7 @@
   glEnd () ;
   glFlush () ;
 
+#if 0
   static int firsttime = TRUE ;
 
   if ( firsttime )
@@ -171,6 +174,8 @@
     outb ( (stereo==-1) ? ~3 : ~2, LPBASE+2 ) ;
     stereo = -stereo ;
   }
+#endif
+  stereo = 0 ;
 }
 
 
