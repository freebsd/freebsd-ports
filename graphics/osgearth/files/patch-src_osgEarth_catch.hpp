--- src/osgEarth/catch.hpp.orig	2023-07-17 06:00:01 UTC
+++ src/osgEarth/catch.hpp
@@ -6523,7 +6523,7 @@ namespace Catch {
 namespace Catch {
 
     struct RandomNumberGenerator {
-        typedef std::ptrdiff_t result_type;
+        typedef std::size_t result_type;
 
         result_type operator()( result_type n ) const { return std::rand() % n; }
 
