--- utils/acc/misc.c.orig
+++ utils/acc/misc.c
@@ -12,7 +12,7 @@
 #else
 #include <fcntl.h>
 #include <stdlib.h>
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
 #include <io.h>
 #endif
 #include <sys/stat.h>
