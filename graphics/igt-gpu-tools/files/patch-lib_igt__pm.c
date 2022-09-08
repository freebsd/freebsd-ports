--- lib/igt_pm.c.orig	2022-08-31 20:00:01 UTC
+++ lib/igt_pm.c
@@ -33,7 +33,9 @@
 #include <string.h>
 #include <unistd.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 #include <dirent.h>
 
