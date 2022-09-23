--- tests/tools_test.c.orig	2022-08-31 20:00:01 UTC
+++ tests/tools_test.c
@@ -28,7 +28,12 @@
 #include <fcntl.h>
 #include <libgen.h>
 #include <unistd.h>
+#ifdef __linux__
 #include <linux/limits.h>
+#elif defined(__FreeBSD__)
+#include <limits.h>
+#define	get_current_dir_name()	getwd(NULL)
+#endif
 
 #define TOOLS "../tools/"
 
