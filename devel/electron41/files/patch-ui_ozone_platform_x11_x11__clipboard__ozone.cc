--- ui/ozone/platform/x11/x11_clipboard_ozone.cc.orig	2026-03-13 16:54:03 UTC
+++ ui/ozone/platform/x11/x11_clipboard_ozone.cc
@@ -14,7 +14,7 @@
 #include "ui/base/clipboard/clipboard_constants.h"
 #include "ui/base/x/x11_clipboard_helper.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_view_util.h"
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #endif
@@ -39,7 +39,7 @@ void X11ClipboardOzone::OfferClipboardData(
   for (const auto& item : data_map)
     helper_->InsertMapping(item.first, item.second);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto it = data_map.find(kMimeTypeUriList);
   if (it != data_map.end()) {
     std::string unparsed(base::as_string_view(*it->second));
