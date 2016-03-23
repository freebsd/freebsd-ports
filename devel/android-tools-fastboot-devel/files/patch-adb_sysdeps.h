--- adb/sysdeps.h.orig	2015-09-05 00:01:27 UTC
+++ adb/sysdeps.h
@@ -61,11 +61,13 @@
 #endif
 #endif
 
-#ifdef _WIN32
-
+#if !defined(__clang__) || __clang_major__ < 3 || (__clang_major__ == 3 && __clang_minor__ < 7)
 // Clang-only nullability specifiers
 #define _Nonnull
 #define _Nullable
+#endif
+
+#ifdef _WIN32
 
 #include <ctype.h>
 #include <direct.h>
@@ -401,6 +401,11 @@ typedef std::unique_ptr<HANDLE, handle_d
 
 #include <string>
 
+#if defined(__Bitrig__) || defined(__DragonFly__) || \
+    defined(__FreeBSD__) || defined(__OpenBSD__)
+#include <pthread_np.h>
+#endif
+
 #define OS_PATH_SEPARATORS "/"
 #define OS_PATH_SEPARATOR '/'
 #define OS_PATH_SEPARATOR_STR "/"
@@ -627,6 +632,12 @@ static __inline__ bool adb_thread_create
 static __inline__ int adb_thread_setname(const std::string& name) {
 #ifdef __APPLE__
     return pthread_setname_np(name.c_str());
+#elif defined(__Bitrig__) || defined(__DragonFly__) || \
+      defined(__FreeBSD__) || defined(__OpenBSD__)
+    pthread_set_name_np(pthread_self(), name.c_str());
+    return 0;
+#elif defined(__NetBSD__)
+    return pthread_setname_np(pthread_self(), "%s", (void*)name.c_str());
 #else
     const char *s = name.c_str();
 
