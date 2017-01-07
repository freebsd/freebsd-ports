--- gnuradio-runtime/lib/thread/thread.cc.orig	2016-09-02 04:16:12 UTC
+++ gnuradio-runtime/lib/thread/thread.cc
@@ -284,6 +284,7 @@ namespace gr {
     void
     thread_bind_to_processor(gr_thread_t thread, const std::vector<int> &mask)
     {
+#ifdef _GNU_SOURCE
       cpu_set_t set;
       size_t len = sizeof(cpu_set_t);
       std::vector<int> _mask = mask;
@@ -299,6 +300,7 @@ namespace gr {
         s << "thread_bind_to_processor failed with error: " << ret << std::endl;
         throw std::runtime_error(s.str());
       }
+#endif
     }
 
     void
@@ -310,6 +312,7 @@ namespace gr {
     void
     thread_unbind(gr_thread_t thread)
     {
+#ifdef _GNU_SOURCE
       cpu_set_t set;
       size_t len = sizeof(cpu_set_t);
 
@@ -325,6 +328,7 @@ namespace gr {
         s << "thread_unbind failed with error: " << ret << std::endl;
         throw std::runtime_error(s.str());
       }
+#endif
     }
 
     int
