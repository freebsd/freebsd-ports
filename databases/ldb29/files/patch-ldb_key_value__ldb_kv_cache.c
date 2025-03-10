--- ldb_key_value/ldb_kv_cache.c.orig	2022-01-24 10:27:24 UTC
+++ ldb_key_value/ldb_kv_cache.c
@@ -92,7 +92,9 @@ static int ldb_schema_attribute_compare(const void *p1
 {
 	const struct ldb_schema_attribute *sa1 = (const struct ldb_schema_attribute *)p1;
 	const struct ldb_schema_attribute *sa2 = (const struct ldb_schema_attribute *)p2;
-	return ldb_attr_cmp(sa1->name, sa2->name);
+	int res = ldb_attr_cmp(sa1->name, sa2->name);
+
+	return (res) ? res : (sa1->flags > sa2->flags) ? 1 : (sa1->flags < sa2->flags) ? -1 : 0;
 }
 
 /*
