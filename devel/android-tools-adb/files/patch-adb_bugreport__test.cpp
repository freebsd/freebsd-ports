--- adb/bugreport_test.cpp.orig	2016-09-28 18:07:09 UTC
+++ adb/bugreport_test.cpp
@@ -40,6 +40,7 @@ using ::testing::internal::CaptureStdout
 using ::testing::internal::GetCapturedStderr;
 using ::testing::internal::GetCapturedStdout;
 
+#ifdef __linux__
 // Empty function so tests don't need to be linked against file_sync_service.cpp, which requires
 // SELinux and its transitive dependencies...
 bool do_sync_pull(const std::vector<const char*>& srcs, const char* dst, bool copy_attrs,
@@ -47,6 +48,7 @@ bool do_sync_pull(const std::vector<cons
     ADD_FAILURE() << "do_sync_pull() should have been mocked";
     return false;
 }
+#endif
 
 // Empty functions so tests don't need to be linked against commandline.cpp
 DefaultStandardStreamsCallback DEFAULT_STANDARD_STREAMS_CALLBACK(nullptr, nullptr);
