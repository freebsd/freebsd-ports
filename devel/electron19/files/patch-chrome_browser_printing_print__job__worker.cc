--- chrome/browser/printing/print_job_worker.cc.orig	2022-06-19 00:44:35 UTC
+++ chrome/browser/printing/print_job_worker.cc
@@ -216,7 +216,7 @@ void PrintJobWorker::UpdatePrintSettings(base::Value::
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         print_backend->GetPrinterDriverInfo(printer_name));
 
-#if BUILDFLAG(IS_LINUX) && defined(USE_CUPS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info) ==
         mojom::ResultCode::kSuccess) {
