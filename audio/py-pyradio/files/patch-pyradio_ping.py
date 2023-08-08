--- pyradio/ping.py.orig	2022-12-09 15:36:15 UTC
+++ pyradio/ping.py
@@ -49,7 +49,7 @@ def linux_ping(server, count=1, timeout_in_seconds=1):
             return 0 if '100%' in out[0] else 1
         else:
             r=subprocess.Popen(
-                ['ping', '-c', str(count), '-w',
+                ['ping', '-c', str(count), '-t',
                  str(timeout_in_seconds), server],
                 stderr=subprocess.DEVNULL,
                 stdout=subprocess.PIPE
