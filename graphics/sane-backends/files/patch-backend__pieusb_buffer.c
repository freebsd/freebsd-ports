--- backend/pieusb_buffer.c.orig	2015-09-01 00:31:33 UTC
+++ backend/pieusb_buffer.c
@@ -100,6 +100,12 @@
 #include <stdio.h>
 #include <fcntl.h>
 #include <sys/mman.h>
+
+#ifdef HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#endif
+
+#ifdef HAVE_ENDIAN_H
 #include <endian.h>
 
 /* When creating the release backend, make complains about unresolved external
@@ -110,6 +116,8 @@
  #define le16toh(x) __bswap_16 (x)
 #endif
 
+#endif
+
 static void buffer_update_read_index(struct Pieusb_Read_Buffer* buffer, int increment);
 
 /* READER */
