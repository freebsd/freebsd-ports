--- src/Visualizer.cpp.orig	2020-04-04 22:44:14 UTC
+++ src/Visualizer.cpp
@@ -137,7 +137,7 @@ void vis::Visualizer::run()
     m_writer->setup_colors(m_settings->is_override_terminal_colors(),
                            m_settings->get_colors());
 
-    auto last_rotation_timestamp =
+    int64_t last_rotation_timestamp =
         std::chrono::system_clock::now().time_since_epoch() /
         std::chrono::seconds(1);
 
