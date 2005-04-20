--- src/openct/checksum.h.orig	Wed Apr 20 15:18:03 2005
+++ src/openct/checksum.h	Wed Apr 20 15:18:18 2005
@@ -22,7 +22,9 @@
 #ifndef __CHECKSUM_H__
 #define __CHECKSUM_H__
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <unistd.h>
 
 extern unsigned int	csum_lrc_compute(const uint8_t *, size_t, unsigned char *);
