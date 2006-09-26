--- backend/pixma.h.orig	Mon Jun 12 05:56:42 2006
+++ backend/pixma.h	Fri Sep 15 01:11:40 2006
@@ -104,14 +104,14 @@
 
 #include <errno.h>
 
-#ifdef HAVE_STDINT_H
-# include <stdint.h>		/* available in ISO C99 */
+#ifdef HAVE_INTTYPES_H
+# include <inttypes.h>
 #else
 # include <sys/types.h>
 typedef u_int8_t uint8_t;
 typedef u_int16_t uint16_t;
 typedef u_int32_t uint32_t;
-#endif /* HAVE_STDINT_H */
+#endif /* HAVE_INTTYPES_H */
 
 #ifndef EPROTO
 # define EPROTO        10000
