--- chrome/browser/crash_upload_list/crash_upload_list.cc.orig	2021-07-15 19:13:32 UTC
+++ chrome/browser/crash_upload_list/crash_upload_list.cc
@@ -48,7 +48,7 @@ scoped_refptr<UploadList> CreateCrashUploadList() {
 // to log uploads in CrashUploadList::kReporterLogFilename.
 // Linux is handled below.
 #if !(BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-      defined(OS_LINUX))
+      defined(OS_LINUX) || defined(OS_BSD))
   if (crash_reporter::IsCrashpadEnabled()) {
     return new CrashUploadListCrashpad();
   }
