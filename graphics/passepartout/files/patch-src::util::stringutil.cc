--- src/util/stringutil.cc.orig	Fri Oct 31 20:40:15 2003
+++ src/util/stringutil.cc	Fri Oct 31 20:44:29 2003
@@ -17,7 +17,7 @@
 
 bool whitespace(char c)
 {
-  return std::isspace(c);
+  return isspace(c);
 }
 
 std::string strip_whitespace(std::string s, bool front, bool back)
