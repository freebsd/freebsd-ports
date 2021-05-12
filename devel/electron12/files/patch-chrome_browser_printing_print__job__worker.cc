--- chrome/browser/printing/print_job_worker.cc.orig	2021-04-22 07:51:50 UTC
+++ chrome/browser/printing/print_job_worker.cc
@@ -224,7 +224,7 @@ void PrintJobWorker::UpdatePrintSettings(base::Value n
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         print_backend->GetPrinterDriverInfo(printer_name));
 
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && defined(USE_CUPS)
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && defined(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info)) {
       base::Value advanced_settings(base::Value::Type::DICTIONARY);
@@ -234,7 +234,7 @@ void PrintJobWorker::UpdatePrintSettings(base::Value n
       new_settings.SetKey(kSettingAdvancedSettings,
                           std::move(advanced_settings));
     }
-#endif  // (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) &&
+#endif  // (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) &&
         // defined(USE_CUPS)
   }
 
