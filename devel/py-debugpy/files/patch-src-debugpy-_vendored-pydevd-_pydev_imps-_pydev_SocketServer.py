--- src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_SocketServer.py.orig	2021-09-09 10:13:20 UTC
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
 
@@ -703,10 +703,7 @@ class DatagramRequestHandler(BaseRequestHandler):
     """Define self.rfile and self.wfile for datagram sockets."""
 
     def setup(self):
-        try:
-            from cStringIO import StringIO
-        except ImportError:
-            from StringIO import StringIO
+        from io import StringIO
         self.packet, self.socket = self.request
         self.rfile = StringIO(self.packet)
         self.wfile = StringIO()
