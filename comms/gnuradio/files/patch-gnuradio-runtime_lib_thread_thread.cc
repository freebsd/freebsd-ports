--- gnuradio-runtime/lib/thread/thread.cc.orig	2015-04-13 14:32:43 UTC
+++ gnuradio-runtime/lib/thread/thread.cc
@@ -276,6 +276,7 @@ namespace gr {
     void
     thread_bind_to_processor(gr_thread_t thread, const std::vector<int> &mask)
     {
+#ifdef _GNU_SOURCE
       cpu_set_t set;
       size_t len = sizeof(cpu_set_t);
       std::vector<int> _mask = mask;
@@ -291,6 +292,7 @@ namespace gr {
         s << "thread_bind_to_processor failed with error: " << ret << std::endl;
         throw std::runtime_error(s.str());
       }
+#endif
     }
 
     void
@@ -302,6 +304,7 @@ namespace gr {
     void
     thread_unbind(gr_thread_t thread)
     {
+#ifdef _GNU_SOURCE
       cpu_set_t set;
       size_t len = sizeof(cpu_set_t);
 
@@ -317,6 +320,7 @@ namespace gr {
         s << "thread_unbind failed with error: " << ret << std::endl;
         throw std::runtime_error(s.str());
       }
+#endif
     }
 
     int
