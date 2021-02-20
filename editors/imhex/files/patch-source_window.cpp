--- source/window.cpp.orig	2021-02-18 16:11:50 UTC
+++ source/window.cpp
@@ -595,7 +595,7 @@ namespace hex {
 
     void Window::initPlugins() {
         try {
-            auto pluginFolderPath = std::filesystem::path((SharedData::mainArgv)[0]).parent_path() / "plugins";
+            auto pluginFolderPath = std::filesystem::path("%%PREFIX%%/share/imhex/plugins");
             PluginHandler::load(pluginFolderPath.string());
         } catch (std::runtime_error &e) { return; }
 
