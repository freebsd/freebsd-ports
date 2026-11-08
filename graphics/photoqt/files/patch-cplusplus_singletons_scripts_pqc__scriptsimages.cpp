- FreeBSD has no <sys/xattr.h>; emulate getxattr/setxattr/removexattr
  with extattr(2) so the star rating (user.baloo.rating) still works

--- cplusplus/singletons/scripts/pqc_scriptsimages.cpp.orig	2026-07-30 17:47:41 UTC
+++ cplusplus/singletons/scripts/pqc_scriptsimages.cpp
@@ -48,7 +48,26 @@
 #include <pqc_notify_cpp.h>
 #include <pqc_helper.h>
 
-#ifdef Q_OS_UNIX
+#if defined(Q_OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/extattr.h>
+#include <cerrno>
+#include <cstring>
+// FreeBSD has no Linux-style xattr API: map "user.*" attributes onto
+// EXTATTR_NAMESPACE_USER, the same mapping KDE's KFileMetaData uses.
+static ssize_t getxattr(const char *path, const char *name, void *value, size_t size) {
+    if(strncmp(name, "user.", 5) != 0) { errno = ENOTSUP; return -1; }
+    return extattr_get_file(path, EXTATTR_NAMESPACE_USER, name + 5, value, size);
+}
+static int setxattr(const char *path, const char *name, const void *value, size_t size, int) {
+    if(strncmp(name, "user.", 5) != 0) { errno = ENOTSUP; return -1; }
+    return extattr_set_file(path, EXTATTR_NAMESPACE_USER, name + 5, value, size) == -1 ? -1 : 0;
+}
+static int removexattr(const char *path, const char *name) {
+    if(strncmp(name, "user.", 5) != 0) { errno = ENOTSUP; return -1; }
+    return extattr_delete_file(path, EXTATTR_NAMESPACE_USER, name + 5);
+}
+#elif defined(Q_OS_UNIX)
 #include <sys/xattr.h>
 #endif
 
