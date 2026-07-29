--- data/updatePhrase.py.orig	2026-06-05 09:16:48 UTC
+++ data/updatePhrase.py
@@ -18,7 +18,7 @@ def array_updatedb(table_file, table, db_file="array.d
 
 	# update the database
 	for i, j in k:
-		cur.execute('INSERT INTO ' + table + ' (keys, ph) VALUES ("' + i + '", "' + j + '");')
+		cur.execute(f'INSERT INTO {table} (keys, ph) VALUES (?, ?);', (i, j))
 
 	con.commit()
 	con.close()
