-- fix build with workaround for use of deprecated std::char_traits<unsigned char>

--- apps/ngs_roi/png_canvas.h.orig	2026-10-09 02:29:45 UTC
+++ apps/ngs_roi/png_canvas.h
@@ -152,7 +152,7 @@ struct PngIdatChunk
 
 struct PngIdatChunk
 {
-    std::basic_string<unsigned char> data;
+    std::vector<unsigned char> data;
 
     // Returns pointer to the payload.
     unsigned char const * payload() const
