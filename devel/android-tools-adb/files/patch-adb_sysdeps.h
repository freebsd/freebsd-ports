--- adb/sysdeps.h.orig	2019-07-17 19:54:09 UTC
+++ adb/sysdeps.h
@@ -330,6 +330,11 @@ size_t ParseCompleteUTF8(const char* first, const char
 
 #include <cutils/sockets.h>
 
+#if defined(__Bitrig__) || defined(__DragonFly__) || \
+    defined(__FreeBSD__) || defined(__OpenBSD__)
+#include <pthread_np.h>
+#endif
+
 #define OS_PATH_SEPARATORS "/"
 #define OS_PATH_SEPARATOR '/'
 #define OS_PATH_SEPARATOR_STR "/"
@@ -516,6 +521,12 @@ inline int adb_socket_get_local_port(borrowed_fd fd) {
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
     // Both bionic and glibc's pthread_setname_np fails rather than truncating long strings.
     // glibc doesn't have strlcpy, so we have to fake it.
