-- Update regexes in approval tests to handle versioned directory names and 3-component versions.
-- The directory structure in FreeBSD ports often includes the version (e.g., snitch-1.3.2),
-- which was breaking the path-matching regexes. Also updated version matching for 1.3.2.

--- tests/approval_tests/reporter_console.cpp.orig	2026-05-31 20:22:28 UTC
+++ tests/approval_tests/reporter_console.cpp
@@ -22,11 +22,11 @@ TEST_CASE("console reporter", "[reporters]") {
 
     const std::vector<std::regex> ignores = {
         std::regex{R"(, ([0-9.e+\-]{12}) seconds)"},
-        std::regex{R"(snitch v([0-9]+\.[0-9]+\.[0-9]+\.[0-9a-z]+))"},
-        std::regex{R"(at (.+/snitch/tests/approval_tests/).+:([0-9]+))"},
-        std::regex{R"(at (.+/snitch/tests/).+:([0-9]+))"},
-        std::regex{R"(at (.+\\snitch\\tests\\approval_tests\\).+:([0-9]+))"},
-        std::regex{R"(at (.+\\snitch\\tests\\).+:([0-9]+))"},
+        std::regex{R"(snitch v([0-9]+\.[0-9]+\.[0-9]+(?:\.[0-9a-z]+)?))"},
+        std::regex{R"(at (.+/snitch.*/tests/approval_tests/).+:([0-9]+))"},
+        std::regex{R"(at (.+/snitch.*/tests/).+:([0-9]+))"},
+        std::regex{R"(at (.+\\snitch.*\\tests\\approval_tests\\).+:([0-9]+))"},
+        std::regex{R"(at (.+\\snitch.*\\tests\\).+:([0-9]+))"},
         std::regex{R"(^finished: .+\(([0-9.e+\-]{12}s)\))"}};
 
     SECTION("default") {
