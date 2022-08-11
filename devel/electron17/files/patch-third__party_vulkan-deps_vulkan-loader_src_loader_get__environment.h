--- third_party/vulkan-deps/vulkan-loader/src/loader/get_environment.h.orig	2022-05-11 07:07:29 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/get_environment.h
@@ -35,10 +35,10 @@
 char *loader_getenv(const char *name, const struct loader_instance *inst);
 void loader_free_getenv(char *val, const struct loader_instance *inst);
 
-#if defined(WIN32) || defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(WIN32) || defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 
 bool is_high_integrity();
 
 char *loader_secure_getenv(const char *name, const struct loader_instance *inst);
 
-#endif
\ No newline at end of file
+#endif
