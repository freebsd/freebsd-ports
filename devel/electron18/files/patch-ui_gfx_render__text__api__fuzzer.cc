--- ui/gfx/render_text_api_fuzzer.cc.orig	2022-05-19 03:47:20 UTC
+++ ui/gfx/render_text_api_fuzzer.cc
@@ -21,7 +21,7 @@
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_ANDROID) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #include "base/test/test_discardable_memory_allocator.h"
 #endif
 
@@ -44,7 +44,7 @@ struct Environment {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_ANDROID) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
     // Some platforms require discardable memory to use bitmap fonts.
     base::DiscardableMemoryAllocator::SetInstance(
         &discardable_memory_allocator);
@@ -56,7 +56,7 @@ struct Environment {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_ANDROID) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   base::TestDiscardableMemoryAllocator discardable_memory_allocator;
 #endif
 
