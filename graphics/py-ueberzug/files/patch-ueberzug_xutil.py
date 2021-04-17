--- ueberzug/xutil.py.orig	2021-04-17 13:57:48 UTC
+++ ueberzug/xutil.py
@@ -147,10 +147,9 @@ def get_first_pty(pids: list):
     the first process in the passed list which owns one.
     """
     for pid in pids:
-        pty_candidate = '/proc/{pid}/fd/1'.format(pid=pid)
-        with open(pty_candidate) as pty:
-            if os.isatty(pty.fileno()):
-                return pty_candidate
+        process = psutil.Process(pid=pid)
+        if process is not None and process.terminal() is not None:
+            return process.terminal()
 
     return None
 
