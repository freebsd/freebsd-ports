--- ui/base/x/x11_os_exchange_data_provider.cc.orig	2026-03-13 16:54:03 UTC
+++ ui/base/x/x11_os_exchange_data_provider.cc
@@ -28,7 +28,7 @@
 #include "ui/gfx/x/atom_cache.h"
 #include "ui/gfx/x/connection.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #endif
 
@@ -217,7 +217,7 @@ void XOSExchangeDataProvider::SetFilenames(
           base::JoinString(paths, "\n")));
   format_map_.Insert(x11::GetAtom(kMimeTypeUriList), mem);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Synchronously register files to get the key. This blocks the UI thread
   // briefly but ensures the key is ready for the data offer.
   std::string key = ui::clipboard_util::RegisterFilesWithPortal(filenames);
