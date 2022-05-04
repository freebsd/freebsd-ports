--- main/source/window/window.cpp.orig	2022-04-17 23:53:01 UTC
+++ main/source/window/window.cpp
@@ -148,7 +148,6 @@ namespace hex {
         std::signal(SIGSEGV, signalHandler);
         std::signal(SIGINT, signalHandler);
         std::signal(SIGILL, signalHandler);
-        std::signal(SIGABRT, signalHandler);
         std::signal(SIGFPE, signalHandler);
 
         auto imhexLogo      = romfs::get("logo.png");
@@ -597,7 +596,7 @@ namespace hex {
                 return;
 
             for (int i = 0; i < count; i++) {
-                auto path = std::fs::path(reinterpret_cast<const char8_t *>(paths[i]));
+                auto path = std::fs::path(paths[i]);
 
                 bool handled = false;
                 for (const auto &[extensions, handler] : ContentRegistry::FileHandler::getEntries()) {
