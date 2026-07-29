--- data/cin2sqlite.py.orig	2026-06-05 09:16:48 UTC
+++ data/cin2sqlite.py
@@ -163,7 +163,7 @@ def array_updatedb(table_file, db_file="array.db"):
                 else:
                     # Write data to SQL Database
                     r = (str(REG_STACK[-1]) + "\t" + ln).split()
-                    cur.execute('INSERT INTO main (keys, ch, cat, cnt) VALUES ("' + r[1] + '", "' + r[2] + '", "' + r[0] + '", "0")') 
+                    cur.execute('INSERT INTO main (keys, ch, cat, cnt) VALUES (?, ?, ?, ?);', (r[1], r[2], r[0], '0'))
 
         f.close()
         con.commit()
