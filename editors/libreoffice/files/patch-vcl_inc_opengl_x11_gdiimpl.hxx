--- vcl/inc/opengl/x11/gdiimpl.hxx.orig	2015-08-22 06:41:35 UTC
+++ vcl/inc/opengl/x11/gdiimpl.hxx
@@ -16,7 +16,7 @@
 #include "unx/x11/x11gdiimpl.h"
 #include "openglgdiimpl.hxx"
 
-class TextureCombo;
+struct TextureCombo;
 
 class VCL_PLUGIN_PUBLIC X11OpenGLSalGraphicsImpl : public OpenGLSalGraphicsImpl, public X11GraphicsImpl
 {
