https://github.com/zim-desktop-wiki/zim-desktop-wiki/pull/2640

--- zim/notebook/index/__init__.py.orig	2021-11-29 13:46:48 UTC
+++ zim/notebook/index/__init__.py
@@ -138,7 +138,8 @@ class Index(SignalEmitter):
 	def _db_init(self):
 		tables = [r[0] for r in self._db.execute(
 			'SELECT name FROM sqlite_master '
-			'WHERE type="table" and name NOT LIKE "sqlite%"'
+			'WHERE type=? and name NOT LIKE ?',
+			('table', 'sqlite%')
 		)]
 		for table in tables:
 			self._db.execute('DROP TABLE %s' % table)
