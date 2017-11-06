--- hotspot/src/os/bsd/vm/os_bsd.cpp.orig	2017-09-06 22:12:44 UTC
+++ hotspot/src/os/bsd/vm/os_bsd.cpp
@@ -189,7 +189,9 @@ julong os::Bsd::available_memory() {
 #ifdef __FreeBSD__
   static const char *vm_stats[] = {
     "vm.stats.vm.v_free_count",
+#if __FreeBSD_version < 1200016
     "vm.stats.vm.v_cache_count",
+#endif
     "vm.stats.vm.v_inactive_count"
   };
   size_t size;
@@ -775,6 +777,11 @@ static void *java_start(Thread *thread)
   guarantee(unique_thread_id != 0, "unique thread id was not found");
   osthread->set_unique_thread_id(unique_thread_id);
 #endif
+#ifdef __FreeBSD__
+  uint64_t unique_thread_id = os::Bsd::gettid();
+  guarantee(unique_thread_id != 0, "unique thread id was not found");
+  osthread->set_unique_thread_id(unique_thread_id);
+#endif
   // initialize signal mask for this thread
   os::Bsd::hotspot_sigmask(thread);
 
@@ -938,6 +945,11 @@ bool os::create_attached_thread(JavaThre
   guarantee(unique_thread_id != 0, "just checking");
   osthread->set_unique_thread_id(unique_thread_id);
 #endif
+#ifdef __FreeBSD__
+  uint64_t unique_thread_id = os::Bsd::gettid();
+  guarantee(unique_thread_id != 0, "unique thread id was not found");
+  osthread->set_unique_thread_id(unique_thread_id);
+#endif
   osthread->set_pthread_id(::pthread_self());
 
   // initialize floating point control register
