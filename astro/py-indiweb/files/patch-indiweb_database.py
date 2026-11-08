--- indiweb/database.py.orig	2026-10-13 19:02:03 UTC
+++ indiweb/database.py
@@ -129,10 +129,10 @@ class Database(object):
 
         c.execute('SELECT id FROM profile')
         if not c.fetchone():
-            c.execute('INSERT INTO profile (name) VALUES ("Simulators")')
-            c.execute('INSERT INTO driver (profile, label) VALUES (1, "Telescope Simulator")')
-            c.execute('INSERT INTO driver (profile, label) VALUES (1, "CCD Simulator")')
-            c.execute('INSERT INTO driver (profile, label) VALUES (1, "Focuser Simulator")')
+            c.execute('INSERT INTO profile (name) VALUES (\'Simulators\')')
+            c.execute('INSERT INTO driver (profile, label) VALUES (1, \'Telescope Simulator\')')
+            c.execute('INSERT INTO driver (profile, label) VALUES (1, \'CCD Simulator\')')
+            c.execute('INSERT INTO driver (profile, label) VALUES (1, \'Focuser Simulator\')')
             self.__conn.commit()
         c.close()
 
