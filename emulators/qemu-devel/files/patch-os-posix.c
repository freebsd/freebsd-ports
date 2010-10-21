--- a/os-posix.c
+++ b/os-posix.c
@@ -27,6 +27,9 @@
 #include <fcntl.h>
 #include <signal.h>
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 #include <sys/wait.h>
 /*needed for MAP_POPULATE before including qemu-options.h */
 #include <sys/mman.h>
