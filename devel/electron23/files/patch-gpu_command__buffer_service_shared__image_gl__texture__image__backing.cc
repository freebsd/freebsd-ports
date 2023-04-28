--- gpu/command_buffer/service/shared_image/gl_texture_image_backing.cc.orig	2023-02-01 18:43:20 UTC
+++ gpu/command_buffer/service/shared_image/gl_texture_image_backing.cc
@@ -465,7 +465,7 @@ void GLTextureImageBacking::InitializeGLTexture(
 }
 
 void GLTextureImageBacking::CreateEGLImage() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OZONE) || BUILDFLAG(IS_BSD)
   SharedContextState* shared_context_state = factory()->GetSharedContextState();
   ui::ScopedMakeCurrent smc(shared_context_state->context(),
                             shared_context_state->surface());
