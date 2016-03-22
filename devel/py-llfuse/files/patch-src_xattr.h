--- src/xattr.h.orig	2016-02-23 17:14:08 UTC
+++ src/xattr.h
@@ -37,7 +37,7 @@ static ssize_t getxattr_p (char *path, c
                            UNUSED int namespace) {
     return getxattr(path, name, value, size);
 }
-static int setxattr_p (char *path, char *name, void *value, size_t size,
+static ssize_t setxattr_p (char *path, char *name, void *value, size_t size,
                        UNUSED int namespace) {
     return setxattr(path, name, value, size, 0);
 }
@@ -81,7 +81,7 @@ static ssize_t getxattr_p (char *path, c
     return ret;
 }
 
-static int setxattr_p (char *path, char *name, void *value, size_t size,
+static ssize_t setxattr_p (char *path, char *name, void *value, size_t size,
                        int namespace) {
     return extattr_set_file(path, namespace, name, value, size);
 }
