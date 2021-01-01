--- components/crash/content/app/crashpad.cc.orig	2019-03-15 06:37:13 UTC
+++ components/crash/content/app/crashpad.cc
@@ -101,6 +101,12 @@ void InitializeCrashpadImpl(bool initial_client,
                             const std::string& user_data_dir,
                             const base::FilePath& exe_path,
                             bool embedded_handler) {
+
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return;
+#endif
+
   static bool initialized = false;
   DCHECK(!initialized);
   initialized = true;
@@ -119,7 +125,7 @@ void InitializeCrashpadImpl(bool initial_client,
     // as processed by the backend.
     DCHECK(browser_process || process_type == "Chrome Installer" ||
            process_type == "notification-helper");
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
     DCHECK(browser_process);
 #else
 #error Port.
@@ -184,7 +190,7 @@ void InitializeCrashpadImpl(bool initial_client,
   // other "main, first process" to initialize things. There is no "relauncher"
   // on Windows, so this is synonymous with initial_client.
   const bool should_initialize_database_and_set_upload_policy = initial_client;
-#elif defined(OS_LINUX) || defined(OS_ANDROID)
+#elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   const bool should_initialize_database_and_set_upload_policy = browser_process;
 #endif
   if (should_initialize_database_and_set_upload_policy) {
@@ -253,7 +259,9 @@ bool GetUploadsEnabled() {
 }
 
 void DumpWithoutCrashing() {
+#if !defined(OS_BSD)
   CRASHPAD_SIMULATE_CRASH();
+#endif
 }
 
 void GetReports(std::vector<Report>* reports) {
