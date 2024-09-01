--- test/distance/examples/ocr.hpp.orig	2024-07-02 14:50:14 UTC
+++ test/distance/examples/ocr.hpp
@@ -1,6 +1,6 @@
 #pragma once
 #include <cstdint>
-#include <string>
+#include <vector>
 
-extern std::basic_string<uint8_t> ocr_example1;
-extern std::basic_string<uint8_t> ocr_example2;
+extern std::vector<uint8_t> ocr_example1;
+extern std::vector<uint8_t> ocr_example2;
