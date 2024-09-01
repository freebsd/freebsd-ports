--- test/distance/examples/pythonLevenshteinIssue9.cpp.orig	2024-07-02 14:50:14 UTC
+++ test/distance/examples/pythonLevenshteinIssue9.cpp
@@ -2,7 +2,7 @@ namespace pythonLevenshteinIssue9 {
 
 namespace pythonLevenshteinIssue9 {
 
-std::basic_string<uint8_t> example1 = {
+std::vector<uint8_t> example1 = {
     8,  14, 4,  2,  3,  7,  15, 6,  4,  5,  8,  2,  3,  4,  5,  6,  7,  8,  9,  10, 2,  10, 11, 12, 13, 8,
     2,  8,  14, 4,  2,  3,  7,  15, 6,  4,  5,  8,  6,  7,  16, 7,  13, 17, 2,  4,  16, 14, 7,  14, 18, 19,
     8,  20, 14, 4,  21, 13, 20, 22, 8,  2,  3,  4,  5,  6,  20, 8,  9,  10, 2,  10, 11, 12, 13, 8,  18, 14,
@@ -206,7 +206,7 @@ std::basic_string<uint8_t> example1 = {
     9,  8,  6,  7,  3,  7,  23, 4,  41, 7,  51, 8,  48, 69, 43, 6,  4,  9,  11, 20, 2,  13, 32, 5,  8,  18,
     16};
 
-std::basic_string<uint8_t> example2 = {
+std::vector<uint8_t> example2 = {
     3,  4,  5,  6,  7,  8,  9,  10, 2,  10, 11, 12, 13, 8,  2,  8,  41, 7,  9,  7,  13, 3,  18, 10, 5,  2,
     4,  16, 14, 7,  14, 18, 19, 8,  20, 14, 4,  21, 13, 20, 22, 8,  2,  3,  4,  5,  6,  20, 8,  9,  10, 2,
     10, 11, 12, 13, 8,  18, 14, 10, 7,  23, 17, 13, 4,  8,  11, 4,  14, 8,  15, 7,  12, 8,  14, 18, 16, 7,
