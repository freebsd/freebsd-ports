--- python/test/Ice/properties/run.py.orig	2015-12-27 02:42:11.742927971 +0100
+++ python/test/Ice/properties/run.py	2015-12-27 03:06:41.640921970 +0100
@@ -26,7 +26,7 @@
 #
 if sys.version_info[0] == 2:
     configPath = "./config/\xe4\xb8\xad\xe5\x9b\xbd_client.config"
-    decodedPath = configPath.decode("utf-8")
+    decodedPath = configPath
 else:
     configPath = "./config/\u4e2d\u56fd_client.config"
     decodedPath = configPath # No need to decode with Python3, strings are already Unicode
