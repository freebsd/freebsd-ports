--- vendor/core/libcutils/include/private/fs_config.h	2024-08-29 19:46:57.000000000 +0200
+++ vendor/core/libcutils/include/private/fs_config.h	2026-03-21 13:54:46.886972000 +0100
@@ -26,7 +26,20 @@
 #include <stdint.h>
 #include <unistd.h>
 
+#ifdef __linux__
 #include <linux/capability.h>
+#else
+/* Provide Linux capability constants for non-Linux platforms. */
+#ifndef CAP_SETGID
+#define CAP_SETGID 6
+#endif
+#ifndef CAP_SETUID
+#define CAP_SETUID 7
+#endif
+#ifndef CAP_BLOCK_SUSPEND
+#define CAP_BLOCK_SUSPEND 36
+#endif
+#endif
 
 /* Rules for directories and files has moved to system/code/libcutils/fs_config.c */
 
