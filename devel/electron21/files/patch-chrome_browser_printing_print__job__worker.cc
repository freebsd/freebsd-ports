--- chrome/browser/printing/print_job_worker.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/printing/print_job_worker.cc
@@ -195,7 +195,7 @@ void PrintJobWorker::SetSettings(base::Value::Dict new
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         print_backend->GetPrinterDriverInfo(printer_name));
 
-#if BUILDFLAG(IS_LINUX) && defined(USE_CUPS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info) ==
         mojom::ResultCode::kSuccess) {
