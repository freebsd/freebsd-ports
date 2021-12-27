--- source/window/window.cpp.orig	2021-11-28 20:34:17 UTC
+++ source/window/window.cpp
@@ -252,7 +252,6 @@ namespace hex {
         std::signal(SIGSEGV, signalHandler);
         std::signal(SIGINT,  signalHandler);
         std::signal(SIGILL,  signalHandler);
-        std::signal(SIGABRT, signalHandler);
         std::signal(SIGFPE,  signalHandler);
 
         this->m_logoTexture = ImGui::LoadImageFromMemory(imhex_logo, imhex_logo_size);
