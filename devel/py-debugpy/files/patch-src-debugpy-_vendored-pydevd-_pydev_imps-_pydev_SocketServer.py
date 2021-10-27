--- src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_SocketServer.py.orig	2021-10-13 09:14:03 UTC
+++ src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_SocketServer.py
@@ -336,12 +336,12 @@ class BaseServer:
         The default is to print a traceback and continue.
 
         """
-        print '-'*40
-        print 'Exception happened during processing of request from',
-        print client_address
+        print('-'*40)
+        print('Exception happened during processing of request from', end=' ')
+        print(client_address)
         import traceback
         traceback.print_exc() # XXX But this goes to stderr!
-        print '-'*40
+        print('-'*40)
 
 
 class TCPServer(BaseServer):
@@ -528,7 +528,7 @@ class ForkingMixIn:
             if not pid: continue
             try:
                 self.active_children.remove(pid)
-            except ValueError, e:
+            except ValueError as e:
                 raise ValueError('%s. x=%d and list=%r' % (e.message, pid,
                                                            self.active_children))
 
@@ -704,9 +704,9 @@ class DatagramRequestHandler(BaseRequestHandler):
 
     def setup(self):
         try:
-            from cStringIO import StringIO
+            from io import StringIO
         except ImportError:
-            from StringIO import StringIO
+            from io import StringIO
         self.packet, self.socket = self.request
         self.rfile = StringIO(self.packet)
         self.wfile = StringIO()
