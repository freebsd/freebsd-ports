--- test/distance/examples/pythonLevenshteinIssue9.hpp.orig	2024-07-02 14:50:14 UTC
+++ test/distance/examples/pythonLevenshteinIssue9.hpp
@@ -1,8 +1,8 @@
 #pragma once
 #include <cstdint>
-#include <string>
+#include <vector>
 
 namespace pythonLevenshteinIssue9 {
-extern std::basic_string<uint8_t> example1;
-extern std::basic_string<uint8_t> example2;
+extern std::vector<uint8_t> example1;
+extern std::vector<uint8_t> example2;
 } // namespace pythonLevenshteinIssue9
