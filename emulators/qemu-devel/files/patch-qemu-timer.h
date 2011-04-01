--- a/qemu-timer.h
+++ b/qemu-timer.h
@@ -4,6 +4,10 @@
 #include "qemu-common.h"
 #include <time.h>
 #include <sys/time.h>
+#ifdef __FreeBSD__	/* for __FreeBSD_version */
+#include <sys/param.h>
+#endif
+#include <sys/time.h>
 
 #ifdef _WIN32
 #include <windows.h>
