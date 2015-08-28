--- src/appleseed.cli/continuoussavingtilecallback.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed.cli/continuoussavingtilecallback.cpp
@@ -85,7 +85,7 @@ namespace
         }
 
       private:
-        mutex               m_mutex;
+        boost::mutex        m_mutex;
         filesystem::path    m_output_path;
         filesystem::path    m_tmp_output_path;
         bool                m_write_tiled_image;
@@ -95,7 +95,7 @@ namespace
             const size_t    tile_x,
             const size_t    tile_y) APPLESEED_OVERRIDE
         {
-            mutex::scoped_lock lock(m_mutex);
+            boost::mutex::scoped_lock lock(m_mutex);
             ProgressTileCallback::do_post_render_tile(frame, tile_x, tile_y);
             frame->write_main_image(m_tmp_output_path.string().c_str());
             filesystem::rename(m_tmp_output_path, m_output_path);
