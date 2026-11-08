--- fdbserver/SimulatedCluster.actor.cpp.orig	2025-01-15 16:19:53 UTC
+++ fdbserver/SimulatedCluster.actor.cpp
@@ -87,7 +87,7 @@ class TestConfig {
 // environment details
 class TestConfig {
 	class ConfigBuilder {
-		using value_type = toml::basic_value<toml::discard_comments>;
+		using value_type = toml::value;
 		using base_variant = std::variant<int, bool, std::string, std::vector<int>, ConfigDBType>;
 		using types =
 		    variant_map<variant_concat<base_variant, variant_map<base_variant, Optional>>, std::add_pointer_t>;
