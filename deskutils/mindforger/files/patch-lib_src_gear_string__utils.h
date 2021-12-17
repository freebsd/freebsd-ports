--- lib/src/gear/string_utils.h.orig	2020-03-08 17:03:52 UTC
+++ lib/src/gear/string_utils.h
@@ -114,12 +114,12 @@ static inline char *stringTrim(const char *s) {
 }
 
 static inline std::string &stringLeftTrim(std::string& s) {
-    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(isspace))));
+    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) { return !std::isspace(c); }));
     return s;
 }
 
 static inline std::string &stringRightTrim(std::string& s) {
-    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(isspace))).base(), s.end());
+    s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) { return !std::isspace(c); }).base(), s.end());
     return s;
 }
 
