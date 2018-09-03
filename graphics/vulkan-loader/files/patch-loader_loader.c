--- loader/loader.c.orig	2018-08-03 22:10:42 UTC
+++ loader/loader.c
@@ -215,7 +215,7 @@ void *loader_device_heap_realloc(const struct loader_d
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__)
 
 static inline char *loader_getenv(const char *name, const struct loader_instance *inst) {
     // No allocation of memory necessary for Linux, but we should at least touch
@@ -225,7 +225,7 @@ static inline char *loader_getenv(const char *name, co
 }
 
 static inline char *loader_secure_getenv(const char *name, const struct loader_instance *inst) {
-#if defined(__APPLE__)
+#if !defined(__linux__)
     // Apple does not appear to have a secure getenv implementation.
     // The main difference between secure getenv and getenv is that secure getenv
     // returns NULL if the process is being run with elevated privileges by a normal user.
