--- libsrc/iofuncs/im_mapfile.c.orig	Fri Dec 19 19:26:34 2003
+++ libsrc/iofuncs/im_mapfile.c	Fri Dec 19 19:26:51 2003
@@ -68,10 +68,10 @@
 #include <errno.h>
 #include <assert.h>
 
+#include <sys/types.h>
 #ifdef HAVE_SYS_MMAN_H
 #include <sys/mman.h>
 #endif /*HAVE_SYS_MMAN_H*/
-#include <sys/types.h>
 #ifdef HAVE_SYS_FILE_H
 #include <sys/file.h>
 #endif /*HAVE_SYS_FILE_H*/
