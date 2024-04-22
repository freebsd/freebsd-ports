--- third_party/blink/renderer/core/layout/layout_view.cc.orig	2024-02-21 00:20:53 UTC
+++ third_party/blink/renderer/core/layout/layout_view.cc
@@ -72,7 +72,7 @@
 #include "ui/gfx/geometry/quad_f.h"
 #include "ui/gfx/geometry/size_conversions.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #endif
 
@@ -813,7 +813,7 @@ void LayoutView::UpdateLayout() {
     intrinsic_logical_widths_ = LogicalWidth();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The font code in FontPlatformData does not have a direct connection to the
   // document, the frame or anything from which we could retrieve the device
   // scale factor. After using zoom for DSF, the GraphicsContext does only ever
