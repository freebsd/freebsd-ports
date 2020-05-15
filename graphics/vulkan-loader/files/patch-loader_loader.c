--- loader/loader.c.orig	2020-04-02 16:20:56 UTC
+++ loader/loader.c
@@ -234,7 +234,7 @@ void *loader_device_heap_realloc(const struct loader_d
 }
 
 // Environment variables
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__unix__)
 
 static inline bool IsHighIntegrity() {
     return geteuid() != getuid() || getegid() != getgid();
@@ -249,7 +249,7 @@ static inline char *loader_getenv(const char *name, co
 
 static inline char *loader_secure_getenv(const char *name, const struct loader_instance *inst) {
     char *out;
-#if defined(__APPLE__)
+#if !defined(__linux__)
     // Apple does not appear to have a secure getenv implementation.
     // The main difference between secure getenv and getenv is that secure getenv
     // returns NULL if the process is being run with elevated privileges by a normal user.
