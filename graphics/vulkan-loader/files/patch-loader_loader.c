--- loader/loader.c.orig	2020-11-23 16:19:03 UTC
+++ loader/loader.c
@@ -253,7 +253,7 @@ void *loader_device_heap_realloc(const struct loader_d
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__) || defined(__Fuchsia__)
+#if defined(__unix__) || defined(__APPLE__) || defined(__Fuchsia__)
 
 static inline bool IsHighIntegrity() {
     return geteuid() != getuid() || getegid() != getgid();
@@ -268,7 +268,7 @@ static inline char *loader_getenv(const char *name, co
 
 static inline char *loader_secure_getenv(const char *name, const struct loader_instance *inst) {
     char *out;
-#if defined(__APPLE__)
+#if !defined(__linux__)
     // Apple does not appear to have a secure getenv implementation.
     // The main difference between secure getenv and getenv is that secure getenv
     // returns NULL if the process is being run with elevated privileges by a normal user.
