--- third_party/libsync/src/include/sync/sync.h.orig	2022-05-11 07:04:22 UTC
+++ third_party/libsync/src/include/sync/sync.h
@@ -22,7 +22,9 @@
 #include <sys/cdefs.h>
 #include <stdint.h>
 
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <linux/types.h>
+#endif
 
 __BEGIN_DECLS
 
