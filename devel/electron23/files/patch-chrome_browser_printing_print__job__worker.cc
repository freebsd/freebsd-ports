--- chrome/browser/printing/print_job_worker.cc.orig	2023-02-15 13:08:45 UTC
+++ chrome/browser/printing/print_job_worker.cc
@@ -205,7 +205,7 @@ void PrintJobWorker::SetSettings(base::Value::Dict new
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         print_backend->GetPrinterDriverInfo(printer_name));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info) ==
         mojom::ResultCode::kSuccess) {
