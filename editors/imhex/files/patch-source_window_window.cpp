--- source/window/window.cpp.orig	2022-01-12 08:17:14 UTC
+++ source/window/window.cpp
@@ -279,7 +279,6 @@ namespace hex {
         std::signal(SIGSEGV, signalHandler);
         std::signal(SIGINT,  signalHandler);
         std::signal(SIGILL,  signalHandler);
-        std::signal(SIGABRT, signalHandler);
         std::signal(SIGFPE,  signalHandler);
 
         auto imhexLogo = romfs::get("logo.png");
