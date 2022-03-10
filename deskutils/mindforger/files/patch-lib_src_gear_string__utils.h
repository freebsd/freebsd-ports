--- lib/src/gear/string_utils.h.orig	2022-01-09 17:09:45 UTC
+++ lib/src/gear/string_utils.h
@@ -118,13 +118,13 @@ static inline std::string &stringLeftTrim(std::string&
         s.begin(),
         std::find_if(s.begin(),
         s.end(),
-        std::not1(std::ptr_fun<int, int>(isspace)))
+        [](int c) { return !std::isspace(c); })
     );
     return s;
 }
 
 static inline std::string &stringRightTrim(std::string& s) {
-    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(isspace))).base(), s.end());
+    s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) { return !std::isspace(c); }).base(), s.end());
     return s;
 }
 
