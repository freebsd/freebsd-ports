--- gpu/command_buffer/service/shared_image_backing_gl_texture.cc.orig	2022-05-25 04:01:02 UTC
+++ gpu/command_buffer/service/shared_image_backing_gl_texture.cc
@@ -257,7 +257,7 @@ void SharedImageBackingGLTexture::InitializeGLTexture(
 }
 
 void SharedImageBackingGLTexture::CreateEGLImage() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(USE_OZONE) || BUILDFLAG(IS_BSD)
   SharedContextState* shared_context_state = factory()->GetSharedContextState();
   ui::ScopedMakeCurrent smc(shared_context_state->context(),
                             shared_context_state->surface());
