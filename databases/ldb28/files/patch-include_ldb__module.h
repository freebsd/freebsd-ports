--- include/ldb_module.h.orig	2023-03-29 13:42:11 UTC
+++ include/ldb_module.h
@@ -108,6 +108,12 @@ struct ldb_module;
  */
 #define LDB_FLAG_INTERNAL_ACCESS_CHECKED 0x400
 
+/*
+ * indicates that this element's values are shared with another element (for
+ * example, in a shallow copy of an ldb_message) and should not be freed
+ */
+#define LDB_FLAG_INTERNAL_SHARED_VALUES 0x200
+
 /* an extended match rule that always fails to match */
 #define SAMBA_LDAP_MATCH_ALWAYS_FALSE "1.3.6.1.4.1.7165.4.5.1"
 
