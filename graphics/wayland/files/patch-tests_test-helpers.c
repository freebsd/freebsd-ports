--- tests/test-helpers.c.orig	2020-02-11 23:46:03 UTC
+++ tests/test-helpers.c
@@ -25,6 +25,8 @@
 
 #include "config.h"
 
+#include "../config.h"
+
 #include <assert.h>
 #include <errno.h>
 #include <dirent.h>
@@ -41,6 +43,16 @@
 
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
@@ -48,8 +60,8 @@ count_open_fds(void)
 	struct dirent *ent;
 	int count = 0;
 
-	dir = opendir("/proc/self/fd");
-	assert(dir && "opening /proc/self/fd failed.");
+	dir = opendir(OPEN_FDS_DIR);
+	assert(dir && "opening " OPEN_FDS_DIR " failed.");
 
 	errno = 0;
 	while ((ent = readdir(dir))) {
@@ -58,7 +70,7 @@ count_open_fds(void)
 			continue;
 		count++;
 	}
-	assert(errno == 0 && "reading /proc/self/fd failed.");
+	assert(errno == 0 && "reading " OPEN_FDS_DIR " failed.");
 
 	closedir(dir);
 
