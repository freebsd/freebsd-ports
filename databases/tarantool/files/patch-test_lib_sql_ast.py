--- test/lib/sql_ast.py.orig	2011-05-14 12:16:32.000000000 +0000
+++ test/lib/sql_ast.py	2011-12-13 00:23:04.673107891 +0000
@@ -242,22 +242,16 @@
 class StatementSelect(StatementPing):
   reqeust_type = SELECT_REQUEST_TYPE
 
-  def __init__(self, table_name, where, limit):
+  def __init__(self, table_name, where):
     self.namespace_no = table_name
-    self.index_no = None
-    self.key_list = []
-    if not where:
-      self.index_no = 0
-      self.key_list = ["",]
+    if where:
+      (self.index_no, key) = where
+      self.key = [key]
     else:
-      for (index_no, key) in where:
-        self.key_list.append(key)
-        if self.index_no == None:
-          self.index_no = index_no
-        elif self.index_no != index_no:
-          raise RuntimeError("All key values in a disjunction must refer to the same index")
+      self.index_no = 0
+      self.key = [""]
     self.offset = 0
-    self.limit = limit
+    self.limit = 0xffffffff
 
   def pack(self):
     buf = ctypes.create_string_buffer(PACKET_BUF_LEN)
@@ -266,10 +260,8 @@
                      self.index_no,
                      self.offset,
                      self.limit,
-                     len(self.key_list))
-    offset = SELECT_REQUEST_FIXED_LEN
-    for key in self.key_list:
-      (buf, offset) = pack_tuple([key], buf, offset)
+                     1)
+    (buf, offset) = pack_tuple(self.key, buf, SELECT_REQUEST_FIXED_LEN)
 
     return buf[:offset]
 
