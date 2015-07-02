--- hotspot/src/os/bsd/vm/os_bsd.cpp.orig
+++ hotspot/src/os/bsd/vm/os_bsd.cpp
@@ -1234,14 +1234,14 @@
 pid_t os::Bsd::gettid() {
   int retval = -1;
 
-#ifdef __APPLE__ //XNU kernel
+#if defined(__APPLE__) //XNU kernel
   // despite the fact mach port is actually not a thread id use it
   // instead of syscall(SYS_thread_selfid) as it certainly fits to u4
   retval = ::pthread_mach_thread_np(::pthread_self());
   guarantee(retval != 0, "just checking");
   return retval;
 
-#elifdef __FreeBSD__
+#elif defined(__FreeBSD__)
 #if __FreeBSD_version > 900030
   return ::pthread_getthreadid_np();
 #else
@@ -1249,9 +1249,9 @@
   thr_self(&tid);
   return (pid_t)tid;
 #endif
-#elifdef __OpenBSD__
+#elif defined(__OpenBSD__)
   retval = syscall(SYS_getthrid);
-#elifdef __NetBSD__
+#elif defined(__NetBSD__)
   retval = (pid_t) _lwp_self();
 #endif
 
