Description: Replace the telnetlib-based monitor client (telnetlib was removed
  in Python 3.13) with a socket/selectors loop.
Issue ID: none
Changeset: none (local rewrite; upstream removed telnetlib differently in
  https://github.com/dabeaz/curio/commit/751b0d313c)
TODO: Upstream was archived on 2025-12-21, no further release expected; keep.

--- curio/monitor.py.orig	2022-10-25 14:18:45 UTC
+++ curio/monitor.py
@@ -55,7 +55,7 @@ import threading
 import time
 import socket
 import threading
-import telnetlib
+import selectors
 import argparse
 import logging
 import sys
@@ -289,14 +289,29 @@ def monitor_client(host, port):
     '''
     Client to connect to the monitor via "telnet"
     '''
-    tn = telnetlib.Telnet()
-    tn.open(host, port, timeout=0.5)
+    sock = socket.create_connection((host, port), timeout=0.5)
+    sel = selectors.DefaultSelector()
+    sel.register(sock, selectors.EVENT_READ)
+    sel.register(sys.stdin, selectors.EVENT_READ)
     try:
-        tn.interact()
+        while True:
+            for key, _ in sel.select():
+                if key.fileobj is sock:
+                    data = sock.recv(1000)
+                    if not data:
+                        return
+                    sys.stdout.write(data.decode('ascii', 'replace'))
+                    sys.stdout.flush()
+                else:
+                    line = sys.stdin.readline()
+                    if not line:
+                        return
+                    sock.sendall(line.encode('ascii'))
     except KeyboardInterrupt:
         pass
     finally:
-        tn.close()
+        sel.close()
+        sock.close()
 
 
 def main():
