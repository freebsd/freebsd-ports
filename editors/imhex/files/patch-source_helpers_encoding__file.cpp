--- source/helpers/encoding_file.cpp.orig	2021-09-12 05:41:36 UTC
+++ source/helpers/encoding_file.cpp
@@ -1,6 +1,6 @@
 #include "helpers/encoding_file.hpp"
 
-#include <ranges>
+#include <range/v3/view.hpp>
 #include <hex/helpers/utils.hpp>
 
 #include <fstream>
@@ -17,7 +17,7 @@ namespace hex {
     }
 
     std::pair<std::string_view, size_t> EncodingFile::getEncodingFor(const std::vector<u8> &buffer) const {
-        for (const auto &[size, mapping] : this->m_mapping | std::views::reverse) {
+        for (const auto &[size, mapping] : this->m_mapping | ranges::views::reverse) {
             if (size > buffer.size()) continue;
 
             auto key = std::vector<u8>(buffer.begin(), buffer.begin() + size);
