--- source/window/window.cpp.orig	2021-09-30 10:52:12 UTC
+++ source/window/window.cpp
@@ -248,7 +248,6 @@ namespace hex {
         std::signal(SIGSEGV, signalHandler);
         std::signal(SIGINT,  signalHandler);
         std::signal(SIGILL,  signalHandler);
-        std::signal(SIGABRT, signalHandler);
         std::signal(SIGFPE,  signalHandler);
 
         this->m_logoTexture = ImGui::LoadImageFromMemory(imhex_logo, imhex_logo_size);
