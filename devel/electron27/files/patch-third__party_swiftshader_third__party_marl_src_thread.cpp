--- third_party/swiftshader/third_party/marl/src/thread.cpp.orig	2023-08-10 01:51:25 UTC
+++ third_party/swiftshader/third_party/marl/src/thread.cpp
@@ -444,7 +444,7 @@ void Thread::setName(const char* fmt, ...) {
   pthread_setname_np(name);
 #elif defined(__FreeBSD__)
   pthread_set_name_np(pthread_self(), name);
-#elif !defined(__Fuchsia__) && !defined(__EMSCRIPTEN__)
+#elif !defined(__Fuchsia__) && !defined(__EMSCRIPTEN__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
   pthread_setname_np(pthread_self(), name);
 #endif
 
