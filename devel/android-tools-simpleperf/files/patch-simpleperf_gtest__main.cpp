libc++ fails with higher default.

  [ RUN      ] logging.LOG
  base/logging_test.cpp:162: Failure
  Expected: (output.length()) > (strlen("foobar")), actual: 0 vs 6
  [  FAILED  ] logging.LOG (1 ms)
  [ RUN      ] logging.PLOG
  base/logging_test.cpp:252: Failure
  Expected: (output.length()) > (strlen("foobar")), actual: 0 vs 6
  [  FAILED  ] logging.PLOG (0 ms)

--- simpleperf/gtest_main.cpp	2016-06-28 07:04:19 UTC
+++ simpleperf/gtest_main.cpp
@@ -137,7 +137,7 @@ class SavedPerfHardenProperty {
 int main(int argc, char** argv) {
   InitLogging(argv, android::base::StderrLogger);
   testing::InitGoogleTest(&argc, argv);
-  android::base::LogSeverity log_severity = android::base::WARNING;
+  android::base::LogSeverity log_severity = android::base::GetMinimumLogSeverity();
 
   for (int i = 1; i < argc; ++i) {
     if (strcmp(argv[i], "-t") == 0 && i + 1 < argc) {
