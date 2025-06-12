--- components/to_utf8/to_utf8.hpp.orig	2023-08-08 09:23:20 UTC
+++ components/to_utf8/to_utf8.hpp
@@ -46,7 +46,7 @@ namespace ToUTF8
             inline std::pair<std::size_t, bool> getLengthLegacyEnc(std::string_view input) const;
             inline void copyFromArrayLegacyEnc(std::string_view::iterator& chp, std::string_view::iterator end, char* &out) const;
 
-            const std::basic_string_view<signed char> mTranslationArray;
+            const signed char* mTranslationArray;
     };
 
     class Utf8Encoder
