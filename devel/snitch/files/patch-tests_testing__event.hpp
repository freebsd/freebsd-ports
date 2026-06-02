-- Increase message pool and event capacity in mock_framework and event_catcher.
-- This prevents "message pool is full" crashes in complex tests (like "multiple leaves")
-- that generate more events and strings than the previous small fixed-size buffers allowed.

--- tests/testing_event.hpp.orig	2026-05-31 20:22:28 UTC
+++ tests/testing_event.hpp
@@ -177,16 +177,16 @@ struct mock_framework {
 
 struct mock_framework {
     struct large_data {
-        snitch::registry                             registry;
-        snitch::small_string<4086>                   string_pool;
-        snitch::small_vector<owning_event::data, 32> events;
+        snitch::registry                              registry;
+        snitch::small_string<16384>                   string_pool;
+        snitch::small_vector<owning_event::data, 256> events;
     };
 
     // Put large data on the heap; this can consume too much stack.
-    std::unique_ptr<large_data>                   data        = std::make_unique<large_data>();
-    snitch::registry&                             registry    = data->registry;
-    snitch::small_string<4086>&                   string_pool = data->string_pool;
-    snitch::small_vector<owning_event::data, 32>& events      = data->events;
+    std::unique_ptr<large_data>                    data        = std::make_unique<large_data>();
+    snitch::registry&                              registry    = data->registry;
+    snitch::small_string<16384>&                   string_pool = data->string_pool;
+    snitch::small_vector<owning_event::data, 256>& events      = data->events;
 
     snitch::impl::test_case test_case{
         .id    = {"mock_test", "[mock_tag]", "mock_type"},
@@ -267,14 +267,14 @@ struct event_catcher {
 struct event_catcher {
     struct large_data {
         snitch::registry                                    registry;
-        snitch::small_string<1024>                          string_pool;
+        snitch::small_string<8192>                          string_pool;
         snitch::small_vector<owning_event::data, MaxEvents> events;
     };
 
     // Put large data on the heap; this can consume too much stack.
     std::unique_ptr<large_data>                          data     = std::make_unique<large_data>();
     snitch::registry&                                    registry = data->registry;
-    snitch::small_string<1024>&                          string_pool = data->string_pool;
+    snitch::small_string<8192>&                          string_pool = data->string_pool;
     snitch::small_vector<owning_event::data, MaxEvents>& events      = data->events;
 
     snitch::impl::test_case mock_case{
