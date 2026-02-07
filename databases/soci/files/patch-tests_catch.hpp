--- tests/catch.hpp.orig	2022-02-10 19:13:13 UTC
+++ tests/catch.hpp
@@ -7170,7 +7170,7 @@ namespace Catch {
 namespace Catch {
 
     struct RandomNumberGenerator {
-        typedef std::ptrdiff_t result_type;
+        typedef std::size_t result_type;
 
         result_type operator()( result_type n ) const { return std::rand() % n; }
 
