--- chrome/browser/printing/printer_query.cc.orig	2024-02-27 21:36:00 UTC
+++ chrome/browser/printing/printer_query.cc
@@ -341,7 +341,7 @@ void PrinterQuery::UpdatePrintSettings(base::Value::Di
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         printer_name, print_backend->GetPrinterDriverInfo(printer_name));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS)
+#if (BUILDFLAG(IS_BSD) || BUILDFLAG(IS_LINUX)) && BUILDFLAG(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info) ==
         mojom::ResultCode::kSuccess) {
