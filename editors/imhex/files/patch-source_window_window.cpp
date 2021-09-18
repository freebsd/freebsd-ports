--- source/window/window.cpp.orig	2021-09-18 14:15:40 UTC
+++ source/window/window.cpp
@@ -243,7 +243,6 @@ namespace hex {
         std::signal(SIGSEGV, signalHandler);
         std::signal(SIGINT,  signalHandler);
         std::signal(SIGILL,  signalHandler);
-        std::signal(SIGABRT, signalHandler);
         std::signal(SIGFPE,  signalHandler);
 
         this->m_logoTexture = ImGui::LoadImageFromMemory(imhex_logo, imhex_logo_size);
