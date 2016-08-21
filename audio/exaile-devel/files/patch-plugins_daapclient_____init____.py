Fix SyntaxError with python3 (PEP 3113)

--- plugins/daapclient/__init__.py.orig	2016-08-14 05:19:15 UTC
+++ plugins/daapclient/__init__.py
@@ -307,12 +307,13 @@ class DaapManager:
             
         self.history = DaapHistory(5, menu=hmenu, callback=self.connect_share)
 
-    def connect_share(self, obj, (name, address, port, svc)):
+    def connect_share(self, obj, args):
         '''
             This function is called when a user wants to connec to
         a DAAP share.  It creates a new panel for the share, and
         requests a track list.
         '''
+        name, address, port, svc = args
         conn = DaapConnection(name, address, port)
         
         conn.connect()
