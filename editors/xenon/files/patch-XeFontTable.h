--- XeFontTable.h.orig	Wed Aug  1 04:22:25 2001
+++ XeFontTable.h	Fri Dec  1 20:55:07 2006
@@ -18,21 +18,21 @@
 // hash function object for std::string - maybe move this to Xe.h if it
 // turns out that string keyed hash_maps are used elsewhere
 
-namespace std
+namespace __gnu_cxx
 {
-template<> struct hash<string>
+template<> struct hash<std::string>
 {
-    size_t  operator()(const string& s) const
+    size_t  operator()(const std::string& s) const
     {
 	return __stl_hash_string(s.c_str());
     }
 };
 }
 
-class XeFontTable : public std::hash_map<std::string, XFontStruct*> {
+class XeFontTable : public __gnu_cxx::hash_map<std::string, XFontStruct*> {
 public:
     XeFontTable(void)
-	: std::hash_map<std::string, XFontStruct*>(64) {}
+	: __gnu_cxx::hash_map<std::string, XFontStruct*>(64) {}
     ~XeFontTable();
         
     XFontStruct*	getFont(const char* fontname);
