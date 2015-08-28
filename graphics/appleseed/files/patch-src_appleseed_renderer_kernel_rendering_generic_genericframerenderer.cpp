--- src/appleseed/renderer/kernel/rendering/generic/genericframerenderer.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed/renderer/kernel/rendering/generic/genericframerenderer.cpp
@@ -169,7 +169,7 @@ namespace
                     m_abort_switch,
                     m_is_rendering));
             ThreadFunctionWrapper<PassManagerFunc> wrapper(m_pass_manager_func.get());
-            m_pass_manager_thread.reset(new thread(wrapper));
+            m_pass_manager_thread.reset(new boost::thread(wrapper));
         }
 
         virtual void stop_rendering() APPLESEED_OVERRIDE
@@ -352,7 +352,7 @@ namespace
 
         bool                        m_is_rendering;
         auto_ptr<PassManagerFunc>   m_pass_manager_func;
-        auto_ptr<thread>            m_pass_manager_thread;
+        auto_ptr<boost::thread>     m_pass_manager_thread;
 
         void print_tile_renderers_stats() const
         {
