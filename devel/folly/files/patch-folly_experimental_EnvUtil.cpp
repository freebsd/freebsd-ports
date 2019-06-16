--- folly/experimental/EnvUtil.cpp.orig	2019-06-16 07:49:05 UTC
+++ folly/experimental/EnvUtil.cpp
@@ -27,6 +27,7 @@ using namespace folly::experimental;
 
 EnvironmentState EnvironmentState::fromCurrentEnvironment() {
   std::unordered_map<std::string, std::string> data;
+  extern char **environ;
   for (auto it = environ; it && *it; ++it) {
     std::string key, value;
     folly::StringPiece entry(*it);
