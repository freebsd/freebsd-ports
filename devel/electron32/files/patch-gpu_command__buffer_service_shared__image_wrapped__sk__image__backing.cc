--- gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc.orig	2024-04-15 20:33:59 UTC
+++ gpu/command_buffer/service/shared_image/wrapped_sk_image_backing.cc
@@ -214,7 +214,7 @@ bool WrappedSkImageBacking::Initialize(const std::stri
 
     constexpr GrRenderable is_renderable = GrRenderable::kYes;
     constexpr GrProtected is_protected = GrProtected::kNo;
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // Blue for single-planar and magenta-ish for multi-planar.
     SkColor4f fallback_color =
         format().is_single_plane() ? SkColors::kBlue : SkColors::kWhite;
