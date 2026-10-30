--- sql/auth/sql_authorization.cc.orig	2026-07-10 11:18:36 UTC
+++ sql/auth/sql_authorization.cc
@@ -238,6 +238,10 @@ bool operator==(const Role_id &a, const std::string &b
   return tmp == b;
 }
 
+bool operator==(const Role_id &a, const LEX_CSTRING &b) {
+  return a == to_string(b);
+}
+
 bool operator==(const std::pair<Role_id, bool> &a, const std::string &b) {
   return a.first == b;
 }
