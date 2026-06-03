--- ui/ozone/platform/wayland/host/wayland_clipboard.cc.orig	2026-03-13 16:54:03 UTC
+++ ui/ozone/platform/wayland/host/wayland_clipboard.cc
@@ -34,7 +34,7 @@
 #include "ui/ozone/platform/wayland/host/zwp_primary_selection_device_manager.h"
 #include "ui/ozone/public/platform_clipboard.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_util.h"
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #include "ui/ozone/platform/wayland/host/wayland_exchange_data_provider.h"
@@ -102,7 +102,7 @@ class ClipboardImpl final : public Clipboard, public D
   }
 
   ui::PlatformClipboard::Data ReadFileTransfer() final {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Prefer portal types
     ui::PlatformClipboard::Data data =
         GetDevice()->ReadSelectionData(ui::kMimeTypePortalFileTransfer);
@@ -146,7 +146,7 @@ class ClipboardImpl final : public Clipboard, public D
     } else {
       offered_data_ = *data;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Check if we need to register files for transfer
       auto it = offered_data_.find(ui::kMimeTypeUriList);
       if (it != offered_data_.end()) {
