--- src/gfx.cxx.orig	Sat Nov 10 08:32:52 2001
+++ src/gfx.cxx	Wed Jul  3 04:03:27 2002
@@ -4,9 +4,11 @@
 #ifndef WIN32
 #include <unistd.h>
 #include <string.h>
+#if 0
 #include <sys/io.h>
 #include <sys/perm.h>                                                           
 #endif
+#endif
 
 static unsigned int lastGLUTKeystroke = 0 ;
 
@@ -185,6 +187,7 @@
   glEnd () ;
   glFlush () ;
 
+#if 0
   static int firsttime = TRUE ;
 
   if ( firsttime )
@@ -219,6 +222,8 @@
     outb ( (stereo==-1) ? ~3 : ~2, LPBASE+2 ) ;
     stereo = -stereo ;
   }
+#endif
+  stereo = 0 ;
 }
 
 
