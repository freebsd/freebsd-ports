--- gnuradio-runtime/lib/thread/thread.cc.orig	2013-08-28 13:27:03.000000000 -0500
+++ gnuradio-runtime/lib/thread/thread.cc	2014-03-02 20:19:59.000000000 -0500
@@ -217,6 +217,7 @@
     void
     thread_bind_to_processor(gr_thread_t thread, const std::vector<int> &mask)
     {
+#ifdef _GNU_SOURCE
       cpu_set_t set;
       size_t len = sizeof(cpu_set_t);
       std::vector<int> _mask = mask;
@@ -232,6 +233,7 @@
         s << "thread_bind_to_processor failed with error: " << ret << std::endl;
         throw std::runtime_error(s.str());
       }
+#endif
     }
 
     void
@@ -243,6 +245,7 @@
     void
     thread_unbind(gr_thread_t thread)
     {
+#ifdef _GNU_SOURCE
       cpu_set_t set;
       size_t len = sizeof(cpu_set_t);
 
@@ -258,6 +261,7 @@
         s << "thread_unbind failed with error: " << ret << std::endl;
         throw std::runtime_error(s.str());
       }
+#endif
     }
 
     int 
