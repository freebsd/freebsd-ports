--- pyradio/ping.py.orig	2022-11-25 15:21:16 UTC
+++ pyradio/ping.py
@@ -35,7 +35,7 @@ def linux_ping(server, count=1, timeout_in_seconds=1):
             -1: error
     '''
     try:
-        r=subprocess.Popen(['ping', '-c', str(count), '-w', str(timeout_in_seconds), server ], stdout=subprocess.PIPE).stdout.read()
+        r=subprocess.Popen(['ping', '-c', str(count), '-t', str(timeout_in_seconds), server ], stdout=subprocess.PIPE).stdout.read()
         # print(r)
         return 0 if '100%' in str(r) else 1
     except:
