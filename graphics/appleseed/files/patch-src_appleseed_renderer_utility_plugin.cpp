--- src/appleseed/renderer/utility/plugin.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed/renderer/utility/plugin.cpp
@@ -119,13 +119,13 @@ namespace
     typedef map<string, boost::weak_ptr<SharedLibrary> > PluginCacheType;
 
     PluginCacheType g_plugin_cache;
-    mutex g_plugin_cache_mutex;
+    boost::mutex g_plugin_cache_mutex;
 
     struct PluginDeleter
     {
         void operator()(SharedLibrary* p)
         {
-            lock_guard<mutex> lock(g_plugin_cache_mutex);
+            boost::lock_guard<boost::mutex> lock(g_plugin_cache_mutex);
 
             // Try to call the plugin uninitialize function if defined.
             Plugin::UnInitPluginFnType uninit_fn =
@@ -141,7 +141,7 @@ namespace
 
 auto_release_ptr<Plugin> PluginCache::load(const char* path)
 {
-    lock_guard<mutex> lock(g_plugin_cache_mutex);
+    boost::lock_guard<boost::mutex> lock(g_plugin_cache_mutex);
 
     // Check if we loaded this plugin before.
     PluginCacheType::iterator it = g_plugin_cache.find(path);
