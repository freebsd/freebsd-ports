--- acstore/sqlite_store.py.orig	2024-04-06 08:14:28 UTC
+++ acstore/sqlite_store.py
@@ -57,7 +57,7 @@ def PythonAST2SQL(ast_node):
 
   if isinstance(ast_node, ast.Constant):
     if isinstance(ast_node.value, str):
-      return f'"{ast_node.value:s}"'
+      return f'\'{ast_node.value:s}\''
 
     return str(ast_node.value)
 
@@ -195,7 +195,7 @@ class SQLiteAttributeContainerStore(
 
   _HAS_TABLE_QUERY = (
       'SELECT name FROM sqlite_master '
-      'WHERE type = "table" AND name = "{0:s}"')
+      'WHERE type = \'table\' AND name = \'{0:s}\'')
 
   _INSERT_METADATA_VALUE_QUERY = (
       'INSERT INTO metadata (key, value) VALUES (?, ?)')
@@ -625,7 +625,7 @@ class SQLiteAttributeContainerStore(
     """
     if self.format_version >= self._UPGRADE_COMPATIBLE_FORMAT_VERSION:
       query = (f'UPDATE metadata SET value = {self._FORMAT_VERSION:d} '
-               f'WHERE key = "format_version"')
+               f'WHERE key = \'format_version\'')
 
       try:
         self._cursor.execute(query)
