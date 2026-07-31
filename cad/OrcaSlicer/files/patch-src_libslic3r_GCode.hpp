--- src/libslic3r/GCode.hpp.orig	2025-03-01 00:00:00 UTC
+++ src/libslic3r/GCode.hpp
@@ -176,7 +176,7 @@
     // It is used for the pressure equalizer because it needs to buffer one layer back.
     bool        nop_layer_result { false };
 
-    static LayerResult make_nop_layer_result() { return {"", std::numeric_limits<coord_t>::max(), false, false, true}; }
+    static LayerResult make_nop_layer_result() { return {"", std::numeric_limits<size_t>::max(), false, false, true}; }
 };
 
 class GCode {
