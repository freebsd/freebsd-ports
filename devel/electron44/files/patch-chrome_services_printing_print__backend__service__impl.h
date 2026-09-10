--- chrome/services/printing/print_backend_service_impl.h.orig	2026-06-23 23:37:18 UTC
+++ chrome/services/printing/print_backend_service_impl.h
@@ -28,7 +28,7 @@
 #include "printing/printing_context.h"
 #include "ui/gfx/native_ui_types.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/printing_context_linux.h"
 #endif
 
@@ -242,7 +242,7 @@ class PrintBackendServiceImpl : public mojom::PrintBac
 
   scoped_refptr<PrintBackend> print_backend_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<PrintingContextLinux::PrintDialogFactory>
       print_dialog_factory_;
 #endif
