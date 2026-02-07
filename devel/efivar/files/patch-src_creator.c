--- src/creator.c.orig	2024-01-31 20:08:46 UTC
+++ src/creator.c
@@ -9,16 +9,22 @@
 #include <fcntl.h>
 #include <inttypes.h>
 #include <limits.h>
+#if defined(__linux__)
 #include <mntent.h>
+#endif
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <stdlib.h>
 #include <stdio.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/socket.h>
 
 #include "efiboot.h"
+
+#if defined(__FreeBSD__)
+#  include "mntent.h"
+#endif
 
 static int NONNULL(1, 2, 3)
 find_file(const char * const filepath, char **devicep, char **relpathp)
