--- third_party/vulkan-deps/vulkan-loader/src/loader/get_environment.c.orig	2022-05-25 04:04:41 UTC
+++ third_party/vulkan-deps/vulkan-loader/src/loader/get_environment.c
@@ -31,7 +31,7 @@
 #include "log.h"
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 
 bool is_high_integrity() { return geteuid() != getuid() || getegid() != getgid(); }
 
@@ -43,7 +43,7 @@ char *loader_getenv(const char *name, const struct loa
 }
 
 char *loader_secure_getenv(const char *name, const struct loader_instance *inst) {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
     // Apple does not appear to have a secure getenv implementation.
     // The main difference between secure getenv and getenv is that secure getenv
     // returns NULL if the process is being run with elevated privileges by a normal user.
@@ -163,4 +163,4 @@ void loader_free_getenv(char *val, const struct loader
     (void)inst;
 }
 
-#endif
\ No newline at end of file
+#endif
