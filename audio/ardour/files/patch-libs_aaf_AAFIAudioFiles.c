--- libs/aaf/AAFIAudioFiles.c.orig	2023-12-14 16:14:03 UTC
+++ libs/aaf/AAFIAudioFiles.c
@@ -39,6 +39,9 @@
 #include <arpa/inet.h>
 #include <mntent.h>
 #include <unistd.h> /* access() */
+#elif defined(__FreeBSD__)
+#include <limits.h>
+#include <unistd.h>
 #elif defined(__APPLE__)
 #include <sys/syslimits.h>
 #include <unistd.h> /* access() */
