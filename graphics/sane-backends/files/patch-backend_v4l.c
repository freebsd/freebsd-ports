--- backend/v4l.c.orig	2016-10-06 00:02:57 UTC
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
@@ -1046,7 +1049,7 @@ sane_start (SANE_Handle handle)
   /* v4l1 actually returns BGR when we ask for RGB, so convert it */
   if (s->pict.palette == VIDEO_PALETTE_RGB24)
     {
-      __u32 loop;
+      uint32_t loop;
       DBG (3, "sane_start: converting from BGR to RGB\n");
       for (loop = 0; loop < (s->window.width * s->window.height * 3); loop += 3)
         {
