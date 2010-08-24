--- dcmtk/dcmnet/include/dcompat.h.orig	2010-08-23 16:36:30.000000000 +0200
+++ dcmtk/dcmnet/include/dcompat.h	2010-08-23 16:37:57.000000000 +0200
@@ -146,9 +146,6 @@
 #ifdef HAVE_SYS_SELECT_H
 #include <sys/select.h>
 #endif
-#ifdef HAVE_SYS_FILE_H
-#include <sys/file.h>
-#endif
 
 END_EXTERN_C
 
