--- lib/tests/config_value_test.cc.orig	2016-09-23 20:45:10 UTC
+++ lib/tests/config_value_test.cc
@@ -91,7 +91,7 @@ TEST_CASE("config object unwraps") {
     auto value2 = config_int::new_number(fake_origin(), int64_t(2), "2");
     auto value3 = config_int::new_number(fake_origin(), int64_t(3), "3");
     unordered_map<string, shared_value> org {{"a", value1}, {"b", value2}, {"c", value3}};
-    auto obj = make_shared<const simple_config_object>(fake_origin(), org);
+    auto obj = make_shared<simple_config_object>(fake_origin(), org);
     unordered_map<string, unwrapped_value> map {{"a", 1}, {"b", 2}, {"c", 3}};
     unwrapped_value expected(map);
     bool test = expected == obj->unwrapped();
@@ -103,7 +103,7 @@ TEST_CASE("config list unwraps") {
     auto value2 = config_int::new_number(fake_origin(), int64_t(2), "2");
     auto value3 = config_int::new_number(fake_origin(), int64_t(3), "3");
     vector<shared_value> data { value1, value2, value3 };
-    auto list = make_shared<const simple_config_list>(fake_origin(), data);
+    auto list = make_shared<simple_config_list>(fake_origin(), data);
     vector<unwrapped_value> v { 1,2,3 };
     unwrapped_value expected(v);
     bool test = expected == list->unwrapped();
