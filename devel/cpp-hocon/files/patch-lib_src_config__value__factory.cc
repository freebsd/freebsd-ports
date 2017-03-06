--- lib/src/config_value_factory.cc.orig	2016-09-23 20:45:10 UTC
+++ lib/src/config_value_factory.cc
@@ -17,27 +17,27 @@ namespace hocon {
         // TODO: If use cases of from_any_ref require other types to produce config_nulls,
         // we can revise this behavior
         shared_value operator()(boost::blank null_value) const {
-            return make_shared<const config_null>(nullptr);
+            return make_shared<config_null>(nullptr);
         }
 
         shared_value operator()(string str) const {
-            return make_shared<const config_string>(nullptr, str, config_string_type::QUOTED);
+            return make_shared<config_string>(nullptr, str, config_string_type::QUOTED);
         }
 
         shared_value operator()(int64_t num) const {
-            return make_shared<const config_long>(nullptr, num, "");
+            return make_shared<config_long>(nullptr, num, "");
         }
 
         shared_value operator()(double num) const {
-            return make_shared<const config_double>(nullptr, num, "");
+            return make_shared<config_double>(nullptr, num, "");
         }
 
         shared_value operator()(int num) const {
-            return make_shared<const config_int>(nullptr, num, "");
+            return make_shared<config_int>(nullptr, num, "");
         }
 
         shared_value operator()(bool boolean) const {
-            return make_shared<const config_boolean>(nullptr, boolean);
+            return make_shared<config_boolean>(nullptr, boolean);
         }
 
         shared_value operator()(vector<unwrapped_value> value_list) const {
@@ -45,7 +45,7 @@ namespace hocon {
             for (unwrapped_value v : value_list) {
                 config_values.emplace_back(boost::apply_visitor(config_value_visitor(), v));
             }
-            return make_shared<const simple_config_list>(nullptr, config_values);
+            return make_shared<simple_config_list>(nullptr, config_values);
         }
 
         shared_value operator()(unordered_map<string, unwrapped_value> value_map) const {
@@ -53,7 +53,7 @@ namespace hocon {
             for (auto pair : value_map) {
                 config_map[pair.first] = boost::apply_visitor(config_value_visitor(), pair.second);
             }
-            return make_shared<const simple_config_object>(nullptr, config_map);
+            return make_shared<simple_config_object>(nullptr, config_map);
         }
     };
 
@@ -62,7 +62,7 @@ namespace hocon {
         if (origin.empty()) {
             origin = "hardcoded value";
         }
-        auto conf_origin = make_shared<const simple_config_origin>(origin);
+        auto conf_origin = make_shared<simple_config_origin>(origin);
         return boost::apply_visitor(config_value_visitor(), value)->with_origin(conf_origin);
     }
 }  // namespace hocon
