--- backend/v4l.c.orig	2015-09-20 11:55:39 UTC
+++ backend/v4l.c
@@ -72,7 +72,10 @@
 #include "../include/sane/saneopts.h"
 
 #include <sys/ioctl.h>
+
+#ifdef HAVE_ASM_TYPES_H
 #include <asm/types.h>		/* XXX glibc */
+#endif
 
 #define BACKEND_NAME v4l
 #include "../include/sane/sanei_backend.h"
