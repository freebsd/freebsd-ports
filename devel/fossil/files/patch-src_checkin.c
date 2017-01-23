--- src/checkin.c.orig	2017-01-16 20:58:54 UTC
+++ src/checkin.c
@@ -173,7 +173,7 @@ static void status_report(
       blob_append_sql(&sql, " UNION ALL");
     }
     blob_append_sql(&sql,
-      " SELECT pathname, %s, %s, 0, 0, 0, 0, 0, 0"
+      " SELECT pathname, %s, %s, 0, 0, 0, 0, 0"
       " FROM sfile WHERE pathname NOT IN (%s)%s",
       flags & C_MTIME ? "datetime(mtime, 'unixepoch', toLocal())" : "''",
       flags & C_SIZE ? "size" : "0",
