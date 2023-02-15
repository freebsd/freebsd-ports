--- src/include/pg_version_compat.h.orig	2023-02-15 11:30:17 UTC
+++ src/include/pg_version_compat.h
@@ -54,7 +54,14 @@ pg_strtoint64(char *s)
 	return result;
 }
 
-
+/*
+ * RelationGetSmgr got backported in 13.10 and 14.7 so redefining it for any
+ * version higher causes compilation errors due to redefining of the function.
+ * We want to use it in all versions. So we backport it ourselves in earlier
+ * versions, and rely on the Postgres provided version in the later versions.
+ */
+#if PG_VERSION_NUM >= PG_VERSION_13 && PG_VERSION_NUM < 130010 \
+	|| PG_VERSION_NUM >= PG_VERSION_14 && PG_VERSION_NUM < 140007
 static inline SMgrRelation
 RelationGetSmgr(Relation rel)
 {
@@ -64,6 +71,9 @@ RelationGetSmgr(Relation rel)
 	}
 	return rel->rd_smgr;
 }
+
+
+#endif
 
 
 #define CREATE_SEQUENCE_COMMAND \
