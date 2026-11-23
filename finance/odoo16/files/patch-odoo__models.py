--- odoo/models.py.orig	2026-11-23 14:49:19.104473000 -0800
+++ odoo/models.py	2026-11-23 14:51:20.977210000 -0800
@@ -71,6 +71,7 @@
 regex_object_name = re.compile(r'^[a-z0-9_.]+$')
 regex_pg_name = re.compile(r'^[a-z_][a-z0-9_$]*$', re.I)
 regex_field_agg = re.compile(r'(\w+)(?::(\w+)(?:\((\w+)\))?)?')
+regex_read_group_spec = re.compile(r'(\w+)(?::(\w*))?(?::\w*)*$')
 
 AUTOINIT_RECALCULATE_STORED_FIELDS = 1000
 GC_UNLINK_LIMIT = 100_000
@@ -78,6 +79,17 @@
 INSERT_BATCH_SIZE = 100
 SQL_DEFAULT = psycopg2.extensions.AsIs("DEFAULT")
 
+def parse_read_group_spec(spec: str) -> tuple:
+    """ Return a pair corresponding to the given groupby/aggregate specification. """
+    res_match = regex_read_group_spec.match(spec)
+    if not res_match:
+        raise ValueError(
+            f'Invalid aggregate/groupby specification {spec!r}.\n'
+            '- Valid aggregate specification looks like "<field_name>:<agg>" example: "quantity:sum".\n'
+            '- Valid groupby specification looks like "<no_datish_field_name>" or "<datish_field_name>:<granularity>" example: "date:month".'
+        )
+    return res_match.groups()
+
 def check_object_name(name):
     """ Check if the given name is a valid model name.
 
@@ -2049,6 +2061,7 @@
             Helper method to collect important information about groupbys: raw
             field name, type, time information, qualified name, ...
         """
+        parse_read_group_spec(gb)
         split = gb.split(':')
         field = self._fields.get(split[0])
         if not field:
