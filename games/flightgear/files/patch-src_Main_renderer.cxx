--- src/Main/renderer.cxx.orig	Sun Nov 20 19:23:36 2005
+++ src/Main/renderer.cxx	Sun Nov 20 19:28:43 2005
@@ -122,7 +122,7 @@
 FGRenderer::FGRenderer()
 {
 #ifdef FG_JPEG_SERVER
-   jpgRenderFrame = FGRenderer::update;
+   jpgRenderFrame = &FGRenderer::update;
 #endif
 }
 
