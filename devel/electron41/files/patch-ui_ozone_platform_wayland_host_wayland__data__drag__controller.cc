--- ui/ozone/platform/wayland/host/wayland_data_drag_controller.cc.orig	2026-03-13 16:54:03 UTC
+++ ui/ozone/platform/wayland/host/wayland_data_drag_controller.cc
@@ -49,7 +49,7 @@
 #include "ui/ozone/platform/wayland/host/wayland_window.h"
 #include "ui/ozone/platform/wayland/host/wayland_window_manager.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/clipboard/clipboard_util_linux.h"
 #endif
 
@@ -70,7 +70,7 @@ bool IsPortalMimeType(const std::string& mime_type) {
 constexpr char kMimeTypeEmptyDragData[] = "chromium/x-empty-drag-data";
 
 bool IsPortalMimeType(const std::string& mime_type) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return mime_type == kMimeTypePortalFileTransfer ||
          mime_type == kMimeTypePortalFiles;
 #else
@@ -189,7 +189,7 @@ bool WaylandDataDragController::StartSession(const OSE
   offered_exchange_data_provider_ = data.provider().Clone();
   auto mime_types = GetOfferedExchangeDataProvider()->BuildMimeTypesList();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If we are dragging files, register them with the portal.
   if (data.HasFile()) {
     std::optional<std::vector<FileInfo>> filenames = data.GetFilenames();
@@ -699,7 +699,7 @@ void WaylandDataDragController::PostDataFetchingTask(
         return {};
       }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Handle file transfer via portal
       if (IsPortalMimeType(mime_type)) {
         std::vector<uint8_t> key_vec;
