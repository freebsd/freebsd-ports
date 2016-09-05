--- ./hotspot/src/os/bsd/vm/os_bsd.cpp	2016-06-01 20:57:38.276230000 -0500
+++ ./hotspot/src/os/bsd/vm/os_bsd.cpp	2016-06-01 20:56:46.380667000 -0500
@@ -767,6 +767,11 @@
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
 
@@ -930,6 +935,11 @@
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
