--- libs/aaf/utils.c.orig	2024-04-12 12:56:21 UTC
+++ libs/aaf/utils.c
@@ -32,6 +32,9 @@
 #include <arpa/inet.h>
 #include <mntent.h>
 #include <unistd.h> /* access() */
+#elif defined(__FreeBSD__)
+#include <limits.h>
+#include <unistd.h>
 #elif defined(__APPLE__)
 #include <sys/syslimits.h>
 #include <unistd.h> /* access() */
