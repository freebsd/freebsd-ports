--- ui/ozone/platform/x11/x11_clipboard_ozone.h.orig	2026-04-28 21:06:17 UTC
+++ ui/ozone/platform/x11/x11_clipboard_ozone.h
@@ -14,7 +14,7 @@
 #include "ui/base/x/selection_utils.h"
 #include "ui/ozone/public/platform_clipboard.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/memory/weak_ptr.h"
 #endif
 
@@ -56,7 +56,7 @@ class X11ClipboardOzone : public PlatformClipboard {
  private:
   void OnSelectionChanged(ClipboardBuffer buffer);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void OnPortalKeyRead(PlatformClipboard::RequestDataClosure callback,
                        SelectionData selection_data);
   void OnPathsExtracted(PlatformClipboard::RequestDataClosure callback,
@@ -73,7 +73,7 @@ class X11ClipboardOzone : public PlatformClipboard {
 
   ClipboardDataChangedCallback clipboard_changed_callback_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::WeakPtrFactory<X11ClipboardOzone> weak_factory_{this};
 #endif
 };
