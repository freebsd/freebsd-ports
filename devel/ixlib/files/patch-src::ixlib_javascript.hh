--- src/ixlib_javascript.hh.orig	Fri Nov 28 12:01:06 2003
+++ src/ixlib_javascript.hh	Fri Nov 28 12:41:42 2003
@@ -266,7 +266,11 @@
     // (=unite with) other scopes and keeps a list of registered members
     class list_scope : public value {
       protected:
+#if __GNUC__ < 3
         typedef std::hash_map<std::string,ref<value>,string_hash> member_map;
+#else
+        typedef __gnu_cxx::hash_map<std::string,ref<value>,string_hash> member_map;
+#endif
         typedef std::vector<ref<value> >			swallowed_list;
         
         member_map	MemberMap;
