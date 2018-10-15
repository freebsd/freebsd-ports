--- tests/test-helpers.c.orig	2018-08-24 18:04:36 UTC
+++ tests/test-helpers.c
@@ -25,6 +25,12 @@
 
 #include "config.h"
 
+#include "../config.h"
+
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 #include <assert.h>
 #include <errno.h>
 #include <dirent.h>
@@ -40,6 +46,16 @@
 
 #include "test-runner.h"
 
+#ifdef __FreeBSD__
+/* FreeBSD uses fdescfs (which must be mounted using:
+ *    mount -t fdescfs fdescfs /dev/fd
+ * before the test suite can be run). */
+#define OPEN_FDS_DIR "/dev/fd"
+#else
+/* Linux. */
+#define OPEN_FDS_DIR "/proc/self/fd"
+#endif
+
 int
 count_open_fds(void)
 {
@@ -47,8 +63,8 @@ count_open_fds(void)
 	struct dirent *ent;
 	int count = 0;
 
-	dir = opendir("/proc/self/fd");
-	assert(dir && "opening /proc/self/fd failed.");
+	dir = opendir(OPEN_FDS_DIR);
+	assert(dir && "opening " OPEN_FDS_DIR " failed.");
 
 	errno = 0;
 	while ((ent = readdir(dir))) {
@@ -57,7 +73,7 @@ count_open_fds(void)
 			continue;
 		count++;
 	}
-	assert(errno == 0 && "reading /proc/self/fd failed.");
+	assert(errno == 0 && "reading " OPEN_FDS_DIR " failed.");
 
 	closedir(dir);
 
