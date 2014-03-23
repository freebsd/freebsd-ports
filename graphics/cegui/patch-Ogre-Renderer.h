--- cegui/include/CEGUI/RendererModules/Ogre/Renderer.h.orig	2014-03-11 20:54:16.000000000 +0100
+++ cegui/include/CEGUI/RendererModules/Ogre/Renderer.h	2014-03-11 20:54:26.000000000 +0100
@@ -55,13 +55,7 @@
 class Root;
 class RenderSystem;
 class RenderTarget;
-#if (CEGUI_OGRE_VERSION < ((1 << 16) | (9 << 8) | 0))
 class TexturePtr;
-#else
-template<typename T> class SharedPtr;
-class Texture;
-typedef SharedPtr<Texture> TexturePtr;
-#endif
 class Matrix4;
 }
 
