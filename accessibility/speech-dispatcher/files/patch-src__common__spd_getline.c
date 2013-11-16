--- ./src/common/spd_getline.c.orig	2012-07-11 11:05:05.000000000 +0200
+++ ./src/common/spd_getline.c	2013-11-15 11:25:07.125139008 +0100
@@ -26,6 +26,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <errno.h>
 #include <limits.h>
 #include <glib.h>
@@ -122,3 +123,23 @@
 	}
 	return buf_pos;
 }
+
+ssize_t
+safe_read(int fd, void *buf, size_t count)
+{
+	ssize_t r;
+	do {
+		r = read(fd, buf, count);
+	} while (r == -1 && errno == EINTR);
+	return r;
+}
+
+ssize_t
+safe_write(int fd, const void *buf, size_t count)
+{
+	ssize_t w;
+	do {
+		w = write(fd, buf, count);
+	} while (w == -1 && errno == EINTR);
+	return w;
+}
