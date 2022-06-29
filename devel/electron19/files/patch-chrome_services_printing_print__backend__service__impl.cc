--- chrome/services/printing/print_backend_service_impl.cc.orig	2022-05-25 04:00:51 UTC
+++ chrome/services/printing/print_backend_service_impl.cc
@@ -603,7 +603,7 @@ void PrintBackendServiceImpl::UpdatePrintSettings(
   crash_keys_ = std::make_unique<crash_keys::ScopedPrinterInfo>(
       print_backend_->GetPrinterDriverInfo(*printer_name));
 
-#if BUILDFLAG(IS_LINUX) && defined(USE_CUPS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_CUPS)
   // Try to fill in advanced settings based upon basic info options.
   PrinterBasicInfo basic_info;
   if (print_backend_->GetPrinterBasicInfo(*printer_name, &basic_info) ==
