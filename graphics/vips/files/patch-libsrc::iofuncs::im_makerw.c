--- libsrc/iofuncs/im_makerw.c.orig	Fri Dec 19 19:13:38 2003
+++ libsrc/iofuncs/im_makerw.c	Fri Dec 19 19:13:49 2003
@@ -51,10 +51,10 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #ifdef HAVE_SYS_MMAN_H
 #include <sys/mman.h>
 #endif
-#include <sys/types.h>
 #include <sys/stat.h>
 
 #include <vips/vips.h>
