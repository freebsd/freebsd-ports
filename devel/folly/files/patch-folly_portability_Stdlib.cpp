--- folly/portability/Stdlib.cpp.orig	2019-06-16 07:44:30 UTC
+++ folly/portability/Stdlib.cpp
@@ -149,6 +149,7 @@ int unsetenv(const char* name) {
 
 extern "C" int clearenv() {
   std::vector<std::string> data;
+  extern char **environ;
   for (auto it = environ; it && *it; ++it) {
     std::string entry(*it);
     auto equalsPosition = entry.find('=');
