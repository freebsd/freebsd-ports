--- bstring.cpp.orig	Sun Aug 31 05:49:53 2003
+++ bstring.cpp	Sun Aug 31 05:49:53 2003
@@ -91,7 +91,7 @@
 
 b_string b_string::operator + (const char* s)
 {
-	b_string temp = str;
+	b_string temp (str);
 	return temp += s;
 }
 
