--- components/to_utf8/to_utf8.cpp.orig	2023-08-08 09:23:20 UTC
+++ components/to_utf8/to_utf8.cpp
@@ -52,18 +52,18 @@ namespace
         return std::find_if(input.begin(), input.end(), [] (unsigned char v) { return v == 0 || v >= 128; });
     }
 
-    std::basic_string_view<signed char> getTranslationArray(FromType sourceEncoding)
+    const signed char* getTranslationArray(FromType sourceEncoding)
     {
         switch (sourceEncoding)
         {
             case ToUTF8::WINDOWS_1252:
-                return {ToUTF8::windows_1252, std::size(ToUTF8::windows_1252)};
+                return ToUTF8::windows_1252;
             case ToUTF8::WINDOWS_1250:
-                return {ToUTF8::windows_1250, std::size(ToUTF8::windows_1250)};
+                return ToUTF8::windows_1250;
             case ToUTF8::WINDOWS_1251:
-                return {ToUTF8::windows_1251, std::size(ToUTF8::windows_1251)};
+                return ToUTF8::windows_1251;
             case ToUTF8::CP437:
-                return {ToUTF8::cp437, std::size(ToUTF8::cp437)};
+                return ToUTF8::cp437;
         }
         throw std::logic_error("Invalid source encoding: " + std::to_string(sourceEncoding));
     }
