--- chrome/test/interaction/webui_interaction_test_util.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/test/interaction/webui_interaction_test_util.cc
@@ -54,7 +54,7 @@ class RenderFrameHost;
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #define SUPPORTS_PIXEL_TESTS 1
 #else
 #define SUPPORTS_PIXEL_TESTS 0
