--- ../vcl/unx/source/app/rptpsound.cxx.orig	Fri May 31 17:18:14 2002
+++ ../vcl/unx/source/app/rptpsound.cxx	Fri May 31 17:18:16 2002
@@ -73,7 +73,7 @@
 #include <strhelper.hxx>
 #include <string.h>
 
-#ifdef SOLARIS
+#ifdef SOLARIS || FREEBSD
 // Solaris 2.5.1 misses it in unistd.h
 extern "C" int usleep(unsigned int);
 #endif
