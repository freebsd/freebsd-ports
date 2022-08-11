--- headless/public/headless_browser.cc.orig	2022-05-19 05:17:43 UTC
+++ headless/public/headless_browser.cc
@@ -42,7 +42,7 @@ Options::Options(int argc, const char** argv)
       user_agent(content::BuildUserAgentFromProduct(product_name_and_version)),
       window_size(kDefaultWindowSize),
       font_render_hinting(kDefaultFontRenderHinting) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   gl_implementation = gl::kGLImplementationANGLEName;
   angle_implementation = gl::kANGLEImplementationSwiftShaderForWebGLName;
 #endif
