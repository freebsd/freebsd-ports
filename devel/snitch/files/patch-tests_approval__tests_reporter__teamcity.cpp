-- Update regexes in approval tests to handle versioned directory names.
-- The directory structure in FreeBSD ports often includes the version (e.g., snitch-1.3.2),
-- which was breaking the path-matching regexes.

--- tests/approval_tests/reporter_teamcity.cpp.orig	2026-05-31 20:22:28 UTC
+++ tests/approval_tests/reporter_teamcity.cpp
@@ -29,10 +29,10 @@ TEST_CASE("teamcity reporter", "[reporters]") {
 
     const std::vector<std::regex> ignores = {
         std::regex{R"( duration='([0-9]+)')"},
-        std::regex{R"( (?:message|out)='(.+/snitch/tests/approval_tests/).+:([0-9]+))"},
-        std::regex{R"( (?:message|out)='(.+/snitch/tests/).+:([0-9]+))"},
-        std::regex{R"( (?:message|out)='(.+\\snitch\\tests\\approval_tests\\).+:([0-9]+))"},
-        std::regex{R"( (?:message|out)='(.+\\snitch\\tests\\).+:([0-9]+))"}};
+        std::regex{R"( (?:message|out)='(.+/snitch.*/tests/approval_tests/).+:([0-9]+))"},
+        std::regex{R"( (?:message|out)='(.+/snitch.*/tests/).+:([0-9]+))"},
+        std::regex{R"( (?:message|out)='(.+\\snitch.*\\tests\\approval_tests\\).+:([0-9]+))"},
+        std::regex{R"( (?:message|out)='(.+\\snitch.*\\tests\\).+:([0-9]+))"}};
 
     SECTION("default") {
         const arg_vector args{"test", "--reporter", reporter_name};
