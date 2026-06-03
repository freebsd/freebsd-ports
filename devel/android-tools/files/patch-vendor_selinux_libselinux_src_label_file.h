--- vendor/selinux/libselinux/src/label_file.h	2024-08-29 19:46:57.000000000 +0200
+++ vendor/selinux/libselinux/src/label_file.h	2026-03-21 18:25:49.387620000 +0100
@@ -6,7 +6,16 @@
 #include <string.h>
 
 #include <sys/stat.h>
+#ifdef __FreeBSD__
+#include <sys/extattr.h>
+static inline ssize_t getxattr(const char *path, const char *name,
+    void *value, size_t size)
+{
+	return extattr_get_file(path, EXTATTR_NAMESPACE_SYSTEM, name, value, size);
+}
+#else
 #include <sys/xattr.h>
+#endif
 
 /*
  * regex.h/c were introduced to hold all dependencies on the regular
