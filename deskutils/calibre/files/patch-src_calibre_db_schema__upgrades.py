--- src/calibre/db/schema_upgrades.py.orig	2023-02-17 02:32:09 UTC
+++ src/calibre/db/schema_upgrades.py
@@ -300,7 +300,7 @@ class SchemaUpgrade:
         for field in itervalues(self.field_metadata):
             if field['is_category'] and not field['is_custom'] and 'link_column' in field:
                 table = self.db.get(
-                    'SELECT name FROM sqlite_master WHERE type="table" AND name=?',
+                    'SELECT name FROM sqlite_master WHERE type=\'table\' AND name=?',
                     ('books_%s_link'%field['table'],), all=False)
                 if table is not None:
                     create_tag_browser_view(field['table'], field['link_column'], field['column'])
@@ -376,7 +376,7 @@ class SchemaUpgrade:
         for field in itervalues(self.field_metadata):
             if field['is_category'] and not field['is_custom'] and 'link_column' in field:
                 table = self.db.get(
-                    'SELECT name FROM sqlite_master WHERE type="table" AND name=?',
+                    'SELECT name FROM sqlite_master WHERE type=\'table\' AND name=?',
                     ('books_%s_link'%field['table'],), all=False)
                 if table is not None:
                     create_std_tag_browser_view(field['table'], field['link_column'],
