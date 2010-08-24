--- dcmtk/dcmnet/libsrc/dcompat.cc.orig	2010-08-23 16:38:21.000000000 +0200
+++ dcmtk/dcmnet/libsrc/dcompat.cc	2010-08-23 16:38:31.000000000 +0200
@@ -113,9 +113,6 @@
 #ifdef HAVE_SYS_UTSNAME_H
 #include <sys/utsname.h>
 #endif
-#ifdef HAVE_SYS_FILE_H
-#include <sys/file.h>
-#endif
 #ifdef HAVE_IO_H
 #include <io.h>  /* for access() on Win32 */
 #endif
