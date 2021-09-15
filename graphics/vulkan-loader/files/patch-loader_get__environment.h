--- loader/get_environment.h.orig	2021-09-15 16:41:50 UTC
+++ loader/get_environment.h
@@ -35,7 +35,7 @@
 char *loader_getenv(const char *name, const struct loader_instance *inst);
 void loader_free_getenv(char *val, const struct loader_instance *inst);
 
-#if defined(WIN32) || defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
+#if defined(WIN32) || defined(__unix__) || defined(__APPLE__) || defined(__Fuchsia__) || defined(__QNXNTO__)
 
 bool is_high_integrity();
 
