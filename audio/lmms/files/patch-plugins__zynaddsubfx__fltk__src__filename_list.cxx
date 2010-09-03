--- plugins/zynaddsubfx/fltk/src/filename_list.cxx.orig	2009-12-25 08:49:24.000000000 +0900
+++ plugins/zynaddsubfx/fltk/src/filename_list.cxx	2010-01-22 02:17:11.000000000 +0900
@@ -31,6 +31,10 @@
 #include "flstring.h"
 #include <stdlib.h>
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 
 extern "C" {
 #ifndef HAVE_SCANDIR
@@ -77,7 +81,7 @@
                      Fl_File_Sort_F *sort) {
 #ifndef HAVE_SCANDIR
   int n = scandir(d, list, 0, sort);
-#elif defined(__hpux) || defined(__CYGWIN__) || (__GLIBC__ >= 2 && __GLIBC_MINOR__ >= 10 )
+#elif defined(__hpux) || defined(__CYGWIN__) || (__GLIBC__ >= 2 && __GLIBC_MINOR__ >= 10 ) || (defined(__FreeBSD__) && ( (__FreeBSD_version < 900000 && __FreeBSD_version >= 800501) || (__FreeBSD_version >= 900006)))
   // HP-UX, Cygwin and POSIX (2008) define the comparison function like this:
   int n = scandir(d, list, 0, (int(*)(const dirent **, const dirent **))sort);
 #elif defined(__osf__)
