--- gnuradio-runtime/lib/thread/thread.cc.orig	2014-07-08 16:55:12.000000000 -0400
+++ gnuradio-runtime/lib/thread/thread.cc	2014-07-29 18:42:37.000000000 -0400
@@ -276,6 +276,7 @@
     void
     thread_bind_to_processor(gr_thread_t thread, const std::vector<int> &mask)
     {
+#ifdef _GNU_SOURCE
       cpu_set_t set;
       size_t len = sizeof(cpu_set_t);
       std::vector<int> _mask = mask;
@@ -291,6 +292,7 @@
         s << "thread_bind_to_processor failed with error: " << ret << std::endl;
         throw std::runtime_error(s.str());
       }
+#endif
     }
 
     void
@@ -302,6 +304,7 @@
     void
     thread_unbind(gr_thread_t thread)
     {
+#ifdef _GNU_SOURCE
       cpu_set_t set;
       size_t len = sizeof(cpu_set_t);
 
@@ -317,6 +320,7 @@
         s << "thread_unbind failed with error: " << ret << std::endl;
         throw std::runtime_error(s.str());
       }
+#endif
     }
 
     int
