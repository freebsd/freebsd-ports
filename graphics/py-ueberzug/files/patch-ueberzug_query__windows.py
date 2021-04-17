--- ueberzug/query_windows.py.orig	2021-04-17 15:12:52 UTC
+++ ueberzug/query_windows.py
@@ -2,6 +2,7 @@ import os
 import signal
 import errno
 
+import psutil
 
 def get_command(pid):
     """Figures out the associated command name
@@ -13,8 +14,7 @@ def get_command(pid):
     Returns:
         str: the associated command name
     """
-    with open('/proc/{}/comm'.format(pid), 'r') as commfile:
-        return '\n'.join(commfile.readlines())
+    psutil.Process(pid=pid).name()
 
 
 def is_same_command(pid0, pid1):
