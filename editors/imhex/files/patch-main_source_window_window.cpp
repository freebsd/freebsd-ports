--- main/source/window/window.cpp.orig	2022-02-15 12:57:57 UTC
+++ main/source/window/window.cpp
@@ -151,7 +151,6 @@ namespace hex {
         std::signal(SIGSEGV, signalHandler);
         std::signal(SIGINT, signalHandler);
         std::signal(SIGILL, signalHandler);
-        std::signal(SIGABRT, signalHandler);
         std::signal(SIGFPE, signalHandler);
 
         auto imhexLogo      = romfs::get("logo.png");
