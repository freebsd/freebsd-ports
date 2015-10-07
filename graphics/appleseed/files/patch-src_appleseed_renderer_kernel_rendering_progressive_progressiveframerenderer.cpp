--- src/appleseed/renderer/kernel/rendering/progressive/progressiveframerenderer.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed/renderer/kernel/rendering/progressive/progressiveframerenderer.cpp
@@ -235,7 +235,7 @@ namespace
                     m_ref_image_avg_lum,
                     m_abort_switch));
             m_statistics_thread.reset(
-                new thread(
+                new boost::thread(
                     ThreadFunctionWrapper<StatisticsFunc>(m_statistics_func.get())));
 
             // Create and start the display thread.
@@ -249,7 +249,7 @@ namespace
                         m_params.m_max_fps,
                         m_display_thread_abort_switch));
                 m_display_thread.reset(
-                    new thread(
+                    new boost::thread(
                         ThreadFunctionWrapper<DisplayFunc>(m_display_func.get())));
             }
 
@@ -592,11 +592,11 @@ namespace
         double                              m_ref_image_avg_lum;
 
         auto_ptr<DisplayFunc>               m_display_func;
-        auto_ptr<thread>                    m_display_thread;
+        auto_ptr<boost::thread>             m_display_thread;
         AbortSwitch                         m_display_thread_abort_switch;
 
         auto_ptr<StatisticsFunc>            m_statistics_func;
-        auto_ptr<thread>                    m_statistics_thread;
+        auto_ptr<boost::thread>             m_statistics_thread;
 
         void print_sample_generators_stats() const
         {
