--- fdbserver/SimulatedCluster.actor.cpp.orig	2025-07-02 21:14:39 UTC
+++ fdbserver/SimulatedCluster.actor.cpp
@@ -116,7 +116,7 @@ class TestConfig : public BasicTestConfig {
 // environment details
 class TestConfig : public BasicTestConfig {
 	class ConfigBuilder {
-		using value_type = toml::basic_value<toml::discard_comments>;
+		using value_type = toml::value;
 		using base_variant = std::
 		    variant<int, float, double, bool, std::string, std::vector<int>, std::vector<std::string>, ConfigDBType>;
 		using types =
