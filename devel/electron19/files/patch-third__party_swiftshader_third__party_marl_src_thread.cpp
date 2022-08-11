--- third_party/swiftshader/third_party/marl/src/thread.cpp.orig	2022-05-19 03:52:19 UTC
+++ third_party/swiftshader/third_party/marl/src/thread.cpp
@@ -426,7 +426,7 @@ void Thread::setName(const char* fmt, ...) {
   pthread_setname_np(name);
 #elif defined(__FreeBSD__)
   pthread_set_name_np(pthread_self(), name);
-#elif !defined(__Fuchsia__)
+#elif !defined(__Fuchsia__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
   pthread_setname_np(pthread_self(), name);
 #endif
 
