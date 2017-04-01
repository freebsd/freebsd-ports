--- timg.cc.orig	2016-06-27 04:44:39 UTC
+++ timg.cc
@@ -66,9 +66,9 @@ void CopyToCanvas(const Magick::Image &i
             if (c.alphaQuantum() >= 255)
                 continue;
             result->SetPixel(x, y,
-                             ScaleQuantumToChar(c.redQuantum()),
-                             ScaleQuantumToChar(c.greenQuantum()),
-                             ScaleQuantumToChar(c.blueQuantum()));
+                             MagickCore::ScaleQuantumToChar(c.redQuantum()),
+                             MagickCore::ScaleQuantumToChar(c.greenQuantum()),
+                             MagickCore::ScaleQuantumToChar(c.blueQuantum()));
         }
     }
 }
@@ -222,9 +222,9 @@ void DisplayScrolling(const Magick::Imag
             if (src.alphaQuantum() >= 255)
                 continue;
             RGBCol &dest = fast_image[y * img_width + x];
-            dest.r = ScaleQuantumToChar(src.redQuantum());
-            dest.g = ScaleQuantumToChar(src.greenQuantum());
-            dest.b = ScaleQuantumToChar(src.blueQuantum());
+            dest.r = MagickCore::ScaleQuantumToChar(src.redQuantum());
+            dest.g = MagickCore::ScaleQuantumToChar(src.greenQuantum());
+            dest.b = MagickCore::ScaleQuantumToChar(src.blueQuantum());
         }
     }
 
