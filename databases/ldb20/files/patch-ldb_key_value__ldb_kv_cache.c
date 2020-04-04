--- ldb_key_value/ldb_kv_cache.c.orig	2019-01-14 23:24:45 UTC
+++ ldb_key_value/ldb_kv_cache.c
@@ -90,7 +90,9 @@ static int ldb_schema_attribute_compare(
 {
 	const struct ldb_schema_attribute *sa1 = (const struct ldb_schema_attribute *)p1;
 	const struct ldb_schema_attribute *sa2 = (const struct ldb_schema_attribute *)p2;
-	return ldb_attr_cmp(sa1->name, sa2->name);
+	int res = ldb_attr_cmp(sa1->name, sa2->name);
+
+	return (res) ? res : (sa1->flags > sa2->flags) ? 1 : (sa1->flags < sa2->flags) ? -1 : 0;
 }
 
 /*
