Upstream: https://gitlab.gnome.org/GNOME/gegl/commit/c1c3541caab485384087bbbcf1c83ef2d5bd4d43

diff --git a/operations/external/exr-save.cc b/operations/external/exr-save.cc
index b2032046ccf69f645e52e908bf4fe58ab2b85c6e..018e5d9af0469cc082d12a27af9377ec9b553322 100644
--- operations/external/exr-save.cc
+++ operations/external/exr-save.cc
@@ -145,10 +145,10 @@ write_tiled_exr (const float       *pixels,
                           &blue[0], &blue[1],
                           NULL, NULL, NULL);
     {
-    Imf::Chromaticities c1 (Imath_2_2::V2f(red[0],red[1]),
-                            Imath_2_2::V2f(green[0],green[1]),
-                            Imath_2_2::V2f(blue[0],blue[1]),
-                            Imath_2_2::V2f(wp[0],wp[1]));
+    Imf::Chromaticities c1 (Imath::V2f(red[0],red[1]),
+                            Imath::V2f(green[0],green[1]),
+                            Imath::V2f(blue[0],blue[1]),
+                            Imath::V2f(wp[0],wp[1]));
     Imf::addChromaticities (header, c1);
     }
   }
@@ -184,10 +184,10 @@ write_scanline_exr (const float       *pixels,
                            &green[0], &green[1],
                            &blue[0], &blue[1],
                            NULL, NULL, NULL);
-    Imf::Chromaticities c1 (Imath_2_2::V2f(red[0],red[1]),
-                            Imath_2_2::V2f(green[0],green[1]),
-                            Imath_2_2::V2f(blue[0],blue[1]),
-                            Imath_2_2::V2f(wp[0],wp[1]));
+    Imf::Chromaticities c1 (Imath::V2f(red[0],red[1]),
+                            Imath::V2f(green[0],green[1]),
+                            Imath::V2f(blue[0],blue[1]),
+                            Imath::V2f(wp[0],wp[1]));
     Imf::addChromaticities (header, c1);
   }
 
