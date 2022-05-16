--- components/crash/core/browser/crash_upload_list_crashpad.cc.orig	2022-05-11 07:00:33 UTC
+++ components/crash/core/browser/crash_upload_list_crashpad.cc
@@ -51,9 +51,13 @@ std::vector<UploadList::UploadInfo> CrashUploadListCra
 
 void CrashUploadListCrashpad::ClearUploadList(const base::Time& begin,
                                               const base::Time& end) {
+#if !defined(OS_BSD)
   crash_reporter::ClearReportsBetween(begin, end);
+#endif
 }
 
 void CrashUploadListCrashpad::RequestSingleUpload(const std::string& local_id) {
+#if !defined(OS_BSD)
   crash_reporter::RequestSingleCrashUpload(local_id);
+#endif
 }
