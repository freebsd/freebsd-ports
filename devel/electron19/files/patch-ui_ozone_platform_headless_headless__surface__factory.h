--- ui/ozone/platform/headless/headless_surface_factory.h.orig	2022-05-25 04:01:58 UTC
+++ ui/ozone/platform/headless/headless_surface_factory.h
@@ -26,7 +26,7 @@ class HeadlessSurfaceFactory : public SurfaceFactoryOz
   // SurfaceFactoryOzone:
   std::vector<gl::GLImplementationParts> GetAllowedGLImplementations() override;
   GLOzone* GetGLOzone(const gl::GLImplementationParts& implementation) override;
-#if BUILDFLAG(ENABLE_VULKAN) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   std::unique_ptr<gpu::VulkanImplementation> CreateVulkanImplementation(
       bool use_swiftshader,
       bool allow_protected_memory) override;
