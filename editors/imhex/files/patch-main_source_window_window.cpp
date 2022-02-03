--- main/source/window/window.cpp.orig	2022-01-30 20:55:06 UTC
+++ main/source/window/window.cpp
@@ -280,7 +280,6 @@ namespace hex {
         std::signal(SIGSEGV, signalHandler);
         std::signal(SIGINT, signalHandler);
         std::signal(SIGILL, signalHandler);
-        std::signal(SIGABRT, signalHandler);
         std::signal(SIGFPE, signalHandler);
 
         auto imhexLogo = romfs::get("logo.png");
