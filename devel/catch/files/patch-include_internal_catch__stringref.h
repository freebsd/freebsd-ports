--- include/internal/catch_stringref.h.orig	2022-10-16 09:02:17 UTC
+++ include/internal/catch_stringref.h
@@ -92,12 +92,12 @@ namespace Catch {
     auto operator << ( std::ostream& os, StringRef const& sr ) -> std::ostream&;
 
 
-    constexpr auto operator "" _sr( char const* rawChars, std::size_t size ) noexcept -> StringRef {
+    constexpr auto operator ""_sr( char const* rawChars, std::size_t size ) noexcept -> StringRef {
         return StringRef( rawChars, size );
     }
 } // namespace Catch
 
-constexpr auto operator "" _catch_sr( char const* rawChars, std::size_t size ) noexcept -> Catch::StringRef {
+constexpr auto operator ""_catch_sr( char const* rawChars, std::size_t size ) noexcept -> Catch::StringRef {
     return Catch::StringRef( rawChars, size );
 }
 
