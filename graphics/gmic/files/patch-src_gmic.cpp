--- src/gmic.cpp.orig	2022-06-30 12:35:34 UTC
+++ src/gmic.cpp
@@ -2314,7 +2314,7 @@ inline CImgList<void*>& gmic_runs() {
 }
 
 inline void* get_tid() {
-#if defined(__MACOSX__) || defined(__APPLE__)
+#if defined(__MACOSX__) || defined(__APPLE__) || defined(__FreeBSD__)
   void* tid = (void*)(cimg_ulong)getpid();
 #elif cimg_OS==1
   void* tid = (void*)(cimg_ulong)syscall(SYS_gettid);
@@ -2322,7 +2322,7 @@ inline void* get_tid() {
   void* tid = (void*)(cimg_ulong)GetCurrentThreadId();
 #else
   void* tid = (void*)0;
-#endif // #if defined(__MACOSX__) || defined(__APPLE__)
+#endif // #if defined(__MACOSX__) || defined(__APPLE__) || defined(__FreeBSD__)
   return tid;
 }
 
@@ -10762,7 +10762,7 @@ gmic& gmic::_run(const CImgList<char>& commands_line, 
 #ifdef gmic_is_parallel
 #ifdef PTHREAD_CANCEL_ENABLE
 
-#if defined(__MACOSX__) || defined(__APPLE__)
+#if defined(__MACOSX__) || defined(__APPLE__) || defined(__FreeBSD__)
               const cimg_uint64 stacksize = (cimg_uint64)8*1024*1024;
               pthread_attr_t thread_attr;
               if (!pthread_attr_init(&thread_attr) && !pthread_attr_setstacksize(&thread_attr,stacksize))
