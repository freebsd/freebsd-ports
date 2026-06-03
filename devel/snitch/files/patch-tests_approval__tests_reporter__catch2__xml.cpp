-- Update regexes in approval tests to handle versioned directory names and 3-component versions.
-- The directory structure in FreeBSD ports often includes the version (e.g., snitch-1.3.2),
-- which was breaking the path-matching regexes. Also updated version matching for 1.3.2.

--- tests/approval_tests/reporter_catch2_xml.cpp.orig	2026-05-31 20:22:28 UTC
+++ tests/approval_tests/reporter_catch2_xml.cpp
@@ -37,15 +37,15 @@ TEST_CASE("xml reporter", "[reporters]") {
 
     const std::vector<std::regex> ignores = {
         std::regex{R"|(durationInSeconds="([0-9.e+\-]{12})")|"},
-        std::regex{R"(catch2-version="([0-9]+\.[0-9]+\.[0-9]+\.[0-9a-z]+).snitch)"},
-        std::regex{R"(filename="(.+/snitch/tests/approval_tests/))"},
-        std::regex{R"(filename="(.+/snitch/tests/))"},
-        std::regex{R"(<File>(.+/snitch/tests/approval_tests/))"},
-        std::regex{R"(<File>(.+/snitch/tests/))"},
-        std::regex{R"(filename="(.+\\snitch\\tests\\approval_tests\\))"},
-        std::regex{R"(filename="(.+\\snitch\\tests\\))"},
-        std::regex{R"(<File>(.+\\snitch\\tests\\approval_tests\\))"},
-        std::regex{R"(<File>(.+\\snitch\\tests\\))"},
+        std::regex{R"(catch2-version="([0-9]+\.[0-9]+\.[0-9]+(?:\.[0-9a-z]+)?).snitch)"},
+        std::regex{R"(filename="(.+/snitch.*/tests/approval_tests/))"},
+        std::regex{R"(filename="(.+/snitch.*/tests/))"},
+        std::regex{R"(<File>(.+/snitch.*/tests/approval_tests/))"},
+        std::regex{R"(<File>(.+/snitch.*/tests/))"},
+        std::regex{R"(filename="(.+\\snitch.*\\tests\\approval_tests\\))"},
+        std::regex{R"(filename="(.+\\snitch.*\\tests\\))"},
+        std::regex{R"(<File>(.+\\snitch.*\\tests\\approval_tests\\))"},
+        std::regex{R"(<File>(.+\\snitch.*\\tests\\))"},
         std::regex{R"|(line="([0-9]+)")|"},
         std::regex{R"(<Line>([0-9]+))"}};
 
