--- dir.c.orig	Sat Feb 24 10:55:06 2007
+++ dir.c	Tue May 22 23:22:14 2007
@@ -958,13 +958,19 @@
 #define GLOB_ALLOC_N(type, n) (type *)malloc(sizeof(type) * (n))
 #define GLOB_JUMP_TAG(status) ((status == -1) ? rb_memerror() : rb_jump_tag(status))
 
+/*
+ * ENOTDIR can be returned by stat(2) if a non-leaf element of the path
+ * is not a directory.
+ */
+#define to_be_ignored(e) ((e) == ENOENT || (e) == ENOTDIR)
+
 /* System call with warning */
 static int
 do_stat(const char *path, struct stat *pst, int flags)
 
 {
     int ret = stat(path, pst);
-    if (ret < 0 && errno != ENOENT)
+    if (ret < 0 && !to_be_ignored(errno))
 	sys_warning(path);
 
     return ret;
@@ -974,7 +980,7 @@
 do_lstat(const char *path, struct stat *pst, int flags)
 {
     int ret = lstat(path, pst);
-    if (ret < 0 && errno != ENOENT)
+    if (ret < 0 && !to_be_ignored(errno))
 	sys_warning(path);
 
     return ret;
@@ -984,7 +990,7 @@
 do_opendir(const char *path, int flags)
 {
     DIR *dirp = opendir(path);
-    if (dirp == NULL && errno != ENOENT && errno != ENOTDIR)
+    if (dirp == NULL && !to_be_ignored(errno))
 	sys_warning(path);
 
     return dirp;
