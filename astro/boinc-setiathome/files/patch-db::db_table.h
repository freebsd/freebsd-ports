--- ../db/db_table.h.orig	Mon Apr  5 16:03:33 2004
+++ ../db/db_table.h	Sun Oct  3 15:41:31 2004
@@ -53,6 +53,52 @@
 };
 
 template <typename T>
+class db_table;
+
+template <typename T>
+std::ostream &operator <<(std::ostream &o, const db_type<T> &a) {
+  o << a.print_xml();
+  return o;
+}
+
+template <typename T>
+std::ostream &operator <<(std::ostream &o, const db_table<T> &a) {
+  o << a.me->print_xml();
+  return o;
+}
+
+template <typename T>
+std::istream &operator >>(std::istream &i, db_table<T> &a) {
+  std::string s;
+  std::string s_tag("<");
+  std::string e_tag("</");
+  s_tag+=a._search_tag;
+  e_tag+=a._search_tag;
+  std::string buffer("");
+  bool found=false, done=false;
+  while (!i.eof()  && !done) {
+    i >> s;
+    if (xml_match_tag(s,s_tag.c_str())) {
+      found=true;
+    }
+    if (found) buffer+=(s+' ');
+    if (xml_match_tag(s,e_tag.c_str())) {
+      found=false;
+      done=true;
+    }
+  }
+  a.me->parse_xml(buffer);
+  std::string::size_type p=buffer.find(e_tag);
+  if (p != std::string::npos) {
+    p=buffer.find('>',p+1);
+    if (p != std::string::npos) {
+      i.seekg(p-buffer.size(),std::ios::cur);
+    }
+  }
+  return i;
+}
+
+template <typename T>
 class db_table {
   public:
     db_table(T &t, SQL_CURSOR c);
@@ -332,12 +378,6 @@
   
 #endif
 
-template <typename T>
-std::ostream &operator <<(std::ostream &o, const db_type<T> &a) {
-  o << a.print_xml();
-  return o;
-}
-
 template <typename T, typename ID_TYPE>
 std::ostream &operator <<(std::ostream &o, const db_reference<T,ID_TYPE> &a) {
   o << a.print_xml();
@@ -345,12 +385,6 @@
 }
 
 template <typename T>
-std::ostream &operator <<(std::ostream &o, const db_table<T> &a) {
-  o << a.me->print_xml();
-  return o;
-}
-
-template <typename T>
 const char *db_type<T>::search_tag(const char *s) {
   if (s) {
     _search_tag=s;
@@ -368,37 +402,6 @@
     _search_tag=table_name;
   }
   return _search_tag;
-}
-
-template <typename T>
-std::istream &operator >>(std::istream &i, db_table<T> &a) {
-  std::string s;
-  std::string s_tag("<");
-  std::string e_tag("</");
-  s_tag+=a._search_tag;
-  e_tag+=a._search_tag;
-  std::string buffer("");
-  bool found=false, done=false;
-  while (!i.eof()  && !done) {
-    i >> s;
-    if (xml_match_tag(s,s_tag.c_str())) {
-      found=true;
-    }
-    if (found) buffer+=(s+' ');
-    if (xml_match_tag(s,e_tag.c_str())) {
-      found=false;
-      done=true;
-    }
-  }
-  a.me->parse_xml(buffer);
-  std::string::size_type p=buffer.find(e_tag);
-  if (p != std::string::npos) {
-    p=buffer.find('>',p+1);
-    if (p != std::string::npos) {
-      i.seekg(p-buffer.size(),std::ios::cur);
-    }
-  }
-  return i;
 }
 
 template <typename T>
