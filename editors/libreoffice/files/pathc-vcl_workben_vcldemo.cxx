--- vcl/workben/vcldemo.cxx.orig	2025-10-01 11:38:12 UTC
+++ vcl/workben/vcldemo.cxx
@@ -507,7 +507,7 @@ class DemoRenderer (public)
 
                 // tdf#95222 - justification issue
                 // - FIXME: replicate justification
-                SET("gentium basic", pJustification),
+                SET("gentium", pJustification),
 
                 // tdf#97319 - Unicode beyond BMP; SMP & Plane 2
                 SET("symbola", pEmojis),
