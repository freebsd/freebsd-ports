--- data/updateShortcode.py.orig	2026-06-05 09:16:48 UTC
+++ data/updateShortcode.py
@@ -18,7 +18,7 @@ def array_updatedb(table_file, table, db_file="array.d
 
 	# update the database
 	for i, j in k:
-		cur.execute('INSERT INTO ' + table + ' (keys, ch) VALUES ("' + i + '", "' + j + '");')
+		cur.execute(f'INSERT INTO {table} (keys, ch) VALUES (?, ?);', (i, j))
 
 	con.commit()
 	con.close()
