--- pyradio/ping.py.orig	2025-01-18 18:10:46 UTC
+++ pyradio/ping.py
@@ -42,7 +42,7 @@ def linux_ping(server, count=1, timeout_in_seconds=1):
     '''
     try:
         r = subprocess.Popen(
-            ['ping', '-c', str(count), '-w',
+            ['ping', '-c', str(count), '-t',
              str(timeout_in_seconds), server],
             stderr=subprocess.DEVNULL,
             stdout=subprocess.PIPE
