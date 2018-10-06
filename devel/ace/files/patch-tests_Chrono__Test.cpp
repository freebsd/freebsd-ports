--- tests/Chrono_Test.cpp.orig	2018-10-05 15:55:54 UTC
+++ tests/Chrono_Test.cpp
@@ -208,7 +208,7 @@ test_streamers ()
   std::chrono::seconds day_test_ts { day_test_h+day_test_s };
   std::chrono::microseconds day_test_tus { day_test_ms+day_test_us };
   ACE_Time_Value const test_day {
-    ACE_Time_Value { day_test_ts.count (), ACE_Utils::truncate_cast<suseconds_t>(day_test_tus.count ()) }};
+    ACE_Time_Value { (int)(day_test_ts.count ()), ACE_Utils::truncate_cast<suseconds_t>(day_test_tus.count ()) }};
 
   constexpr int expected_min  {nr_hours * 60};
   constexpr int64_t expected_sec  { expected_min * 60 + 54 };
