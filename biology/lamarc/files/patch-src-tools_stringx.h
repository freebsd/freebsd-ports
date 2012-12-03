--- src/tools/stringx.h.orig	2012-12-03 12:01:34.000000000 +0100
+++ src/tools/stringx.h	2012-12-03 12:02:30.000000000 +0100
@@ -107,6 +107,26 @@
 
 bool ciStringEqual(const std::string& s1, const std::string& s2);
 
+
+// functions for making xmltags and lines of xml
+std::string MakeTag(const std::string& str);
+std::string MakeCloseTag(const std::string& str);
+std::string MakeTagWithName(const std::string& tag, const std::string& name);
+std::string MakeTagWithType(const std::string& tag, const std::string& type);
+std::string MakeTagWithTypePlusPanel(const std::string& tag, const std::string& type);
+std::string MakeTagWithConstraint(const std::string& tag, const std::string& constraint);
+std::string MakeJustified(const std::string & str, long width=DEFLINELENGTH);
+std::string MakeJustified(const char* str, long width=DEFLINELENGTH);
+std::string MakeCentered(const std::string& str, long width=DEFLINELENGTH,
+                         long indent=DEFINDENT, bool trunc=true);
+std::string MakeCentered(const char* str, long width=DEFLINELENGTH,
+                         long indent=DEFINDENT, bool trunc=true);
+std::string MakeIndent(const std::string & str, unsigned long indent);
+std::string MakeIndent(const char* str, unsigned long indent);
+std::string Pretty(double number, int width=DEFWIDTH);
+std::string Pretty(long number, int width=DEFWIDTH);
+std::string Pretty(unsigned long number, int width=DEFWIDTH);
+std::string Pretty(std::string str, int width=DEFWIDTH);
 //------------------------------------------------------------------------------------
 
 template <class T>
@@ -188,26 +208,6 @@
 
 DoubleVec1d StringToDoubleVecOrBarf(const std::string& in);
 
-// functions for making xmltags and lines of xml
-std::string MakeTag(const std::string& str);
-std::string MakeCloseTag(const std::string& str);
-std::string MakeTagWithName(const std::string& tag, const std::string& name);
-std::string MakeTagWithType(const std::string& tag, const std::string& type);
-std::string MakeTagWithTypePlusPanel(const std::string& tag, const std::string& type);
-std::string MakeTagWithConstraint(const std::string& tag, const std::string& constraint);
-std::string MakeJustified(const std::string & str, long width=DEFLINELENGTH);
-std::string MakeJustified(const char* str, long width=DEFLINELENGTH);
-std::string MakeCentered(const std::string& str, long width=DEFLINELENGTH,
-                         long indent=DEFINDENT, bool trunc=true);
-std::string MakeCentered(const char* str, long width=DEFLINELENGTH,
-                         long indent=DEFINDENT, bool trunc=true);
-std::string MakeIndent(const std::string & str, unsigned long indent);
-std::string MakeIndent(const char* str, unsigned long indent);
-std::string Pretty(double number, int width=DEFWIDTH);
-std::string Pretty(long number, int width=DEFWIDTH);
-std::string Pretty(unsigned long number, int width=DEFWIDTH);
-std::string Pretty(std::string str, int width=DEFWIDTH);
-
 bool   StringCompare(const std::string&, const char*, long, long);
 bool   StringCompare(const std::string&, const std::string&, long, long);
 
