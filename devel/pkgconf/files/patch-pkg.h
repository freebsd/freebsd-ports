--- ./pkg.h.orig	2012-07-26 04:13:43.000000000 +0200
+++ ./pkg.h	2012-07-29 11:31:53.000000000 +0200
@@ -114,11 +114,14 @@
 #define PKG_ERRF_PACKAGE_VER_MISMATCH	0x2
 #define PKG_ERRF_PACKAGE_CONFLICT	0x4
 
+typedef void (*pkg_iteration_func_t)(const pkg_t *pkg);
 typedef void (*pkg_traverse_func_t)(pkg_t *pkg, void *data, unsigned int flags);
 
 /* pkg.c */
 void pkg_free(pkg_t *pkg);
 pkg_t *pkg_find(const char *name, unsigned int flags);
+void pkg_scan(const char *search_path, pkg_iteration_func_t func);
+void pkg_scan_all(pkg_iteration_func_t func);
 unsigned int pkg_traverse(pkg_t *root, pkg_traverse_func_t func, void *data, int maxdepth, unsigned int flags);
 unsigned int pkg_verify_graph(pkg_t *root, int depth, unsigned int flags);
 int pkg_compare_version(const char *a, const char *b);
