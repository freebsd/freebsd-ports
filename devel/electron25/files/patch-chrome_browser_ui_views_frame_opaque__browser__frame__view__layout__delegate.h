--- chrome/browser/ui/views/frame/opaque_browser_frame_view_layout_delegate.h.orig	2023-03-30 00:33:44 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_layout_delegate.h
@@ -10,7 +10,7 @@
 #include "build/build_config.h"
 #include "build/chromeos_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "ui/base/ui_base_types.h"
 #endif
 
@@ -97,7 +97,7 @@ class OpaqueBrowserFrameViewLayoutDelegate {
   // Returns true if a client-side shadow should be drawn for restored windows.
   virtual bool ShouldDrawRestoredFrameShadow() const = 0;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Returns which edges of the window are snapped to the edges of the desktop
   // (or "tiled").
   virtual ui::WindowTiledEdges GetTiledEdges() const = 0;
