--- src/hugin1/hugin/TextureManager.cpp.orig	2009-08-21 14:24:25.000000000 +0300
+++ src/hugin1/hugin/TextureManager.cpp	2009-08-21 14:24:30.000000000 +0300
@@ -52,6 +52,8 @@
 #include <GL/glu.h>
 #endif
 
+#define log2(x)	(log(x) / log(2))
+
 TextureManager::TextureManager(PT::Panorama *pano, ViewState *view_state_in)
 {
     m_pano = pano;
