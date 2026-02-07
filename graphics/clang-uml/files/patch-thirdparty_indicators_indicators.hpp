--- thirdparty/indicators/indicators.hpp.orig	2025-03-05 16:32:09 UTC
+++ thirdparty/indicators/indicators.hpp
@@ -1415,8 +1415,8 @@ struct interval {
  */
 
 struct interval {
-  int first;
-  int last;
+  wchar_t first;
+  wchar_t last;
 };
 
 /* auxiliary function for binary search in interval table */
@@ -1666,7 +1666,7 @@ static inline std::wstring utf8_decode(const std::stri
     setlocale(LC_ALL, curLocale.c_str());
     return result;
 }
-#else 
+#else
 static inline std::wstring utf8_decode(const std::string& s) {
     auto r = setlocale(LC_ALL, "");
     std::string curLocale;
