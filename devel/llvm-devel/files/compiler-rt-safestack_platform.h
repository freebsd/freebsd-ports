--- lib/safestack/safestack_platform.h.orig	2019-01-18 22:19:46.188728000 +0000
+++ lib/safestack/safestack_platform.h	2019-01-18 22:14:46.776765000 +0000
@@ -20,6 +20,10 @@
 #include <sys/types.h>
 #include <unistd.h>
 
+#if SANITIZER_FREEBSD
+#include <sys/thr.h>
+#endif
+
 namespace safestack {
 
 inline pid_t GetTid() {
