--- lib/zlib/include/zconf.h.orig	Sun Aug  4 20:51:32 2002
+++ lib/zlib/include/zconf.h	Sun Aug  4 20:53:27 2002
@@ -238,15 +238,25 @@
 #ifdef HAVE_UNISTD_H
 #  include <sys/types.h> /* for off_t */
 #  include <unistd.h>    /* for SEEK_* and off_t */
+#ifndef __FreeBSD__
 #  define z_off_t  off_t
 #endif
+#endif
 #ifndef SEEK_SET
 #  define SEEK_SET        0       /* Seek from beginning of file.  */
 #  define SEEK_CUR        1       /* Seek from current position.  */
 #  define SEEK_END        2       /* Set file pointer to EOF plus "offset" */
 #endif
+#ifndef __FreeBSD__
 #ifndef z_off_t
 #  define  z_off_t long
+#endif
+#else
+/*
+ * This is hard-configured for FreeBSD, since zlib doesn't actually support
+ * using the system off_t for offsets unless off_t is no longer than long.
+ */
+#define z_off_t long
 #endif
 
 /* MVS linker does not support external names larger than 8 bytes */
