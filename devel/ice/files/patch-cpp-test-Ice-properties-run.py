--- cpp/test/Ice/properties/run.py.orig	2015-12-27 03:21:09.629772970 +0100
+++ cpp/test/Ice/properties/run.py	2015-12-27 03:21:20.836761970 +0100
@@ -28,7 +28,7 @@
 #
 if sys.version_info[0] == 2:
     configPath = "./config/\xe4\xb8\xad\xe5\x9b\xbd_client.config"
-    decodedPath = configPath.decode("utf-8")
+    decodedPath = configPath
 else:
     configPath = "./config/\u4e2d\u56fd_client.config"
     decodedPath = configPath # No need to decode with Python3, strings are already Unicode
