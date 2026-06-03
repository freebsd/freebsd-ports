--- kstars/catalogsdb/sqlstatements.cpp.orig
+++ kstars/catalogsdb/sqlstatements.cpp
@@ -317,8 +317,8 @@
 const QString _dso_by_name =
-    "SELECT %1, name like \"%\" || :name || \"%\" AS in_name, long_name like "
-    "\"%\" || :name || \"%\" AS in_lname FROM master WHERE in_name "
+    "SELECT %1, name like '%' || :name || '%' AS in_name, long_name like "
+    "'%' || :name || '%' AS in_lname FROM master WHERE in_name "
     "OR in_lname "
     "ORDER BY name, long_name, "
     "%2 LIMIT :limit";
