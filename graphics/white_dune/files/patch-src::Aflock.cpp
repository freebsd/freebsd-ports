--- src/Aflock.cpp.orig	Fri May 16 12:39:46 2003
+++ src/Aflock.cpp	Fri May 16 22:56:14 2003
@@ -807,7 +807,9 @@
 #ifndef __sgi
 # ifndef __sun
 #  ifndef __APPLE__
+#   ifndef __FreeBSD__
     termIoPort.c_lflag = N_TTY;
+#   endif
 #  endif
 # endif
 #endif
