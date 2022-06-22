--- third_party/blink/renderer/core/layout/layout_view.cc.orig	2022-05-19 05:17:47 UTC
+++ third_party/blink/renderer/core/layout/layout_view.cc
@@ -64,7 +64,7 @@
 #include "ui/display/screen_info.h"
 #include "ui/gfx/geometry/quad_f.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/platform/fonts/font_cache.h"
 #endif
 
@@ -359,7 +359,7 @@ void LayoutView::UpdateLayout() {
   DCHECK(!layout_state_);
   LayoutState root_layout_state(*this);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The font code in FontPlatformData does not have a direct connection to the
   // document, the frame or anything from which we could retrieve the device
   // scale factor. After using zoom for DSF, the GraphicsContext does only ever
