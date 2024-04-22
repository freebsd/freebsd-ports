--- src/layout.cpp.orig	2024-01-14 09:10:02 UTC
+++ src/layout.cpp
@@ -43,7 +43,7 @@ void Layout::update(size_t width, size_t height)
     level_height = height;
 
     // size of header and footer
-    size_t header_h = std::min(64ul, static_cast<size_t>(window.h) / 10);
+    size_t header_h = std::min((size_t)64, static_cast<size_t>(window.h) / 10);
 
     // size of a single puzzle cell
     const int max_wnd_w = window.w - padding * 2;
