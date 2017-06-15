--- tests/test-helpers.c.orig	2015-07-06 19:38:51 UTC
+++ tests/test-helpers.c
@@ -23,6 +23,12 @@
  * SOFTWARE.
  */
 
+#include "../config.h"
+
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 #include <assert.h>
 #include <errno.h>
 #include <dirent.h>
@@ -32,6 +38,16 @@
 
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
@@ -39,8 +55,8 @@ count_open_fds(void)
 	struct dirent *ent;
 	int count = 0;
 
-	dir = opendir("/proc/self/fd");
-	assert(dir && "opening /proc/self/fd failed.");
+	dir = opendir(OPEN_FDS_DIR);
+	assert(dir && "opening " OPEN_FDS_DIR " failed.");
 
 	errno = 0;
 	while ((ent = readdir(dir))) {
@@ -49,7 +65,7 @@ count_open_fds(void)
 			continue;
 		count++;
 	}
-	assert(errno == 0 && "reading /proc/self/fd failed.");
+	assert(errno == 0 && "reading " OPEN_FDS_DIR " failed.");
 
 	closedir(dir);
 
