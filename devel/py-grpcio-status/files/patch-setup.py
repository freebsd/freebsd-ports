--- setup.py.orig	2025-05-30 16:23:52 UTC
+++ setup.py
@@ -63,7 +63,7 @@ INSTALL_REQUIRES = (
 }
 
 INSTALL_REQUIRES = (
-    "protobuf>=6.31.1,<7.0.0",
+    "protobuf>=5.26.1,<7.0.0",
     "grpcio>={version}".format(version=grpc_version.VERSION),
     "googleapis-common-protos>=1.5.5",
 )
