--- setup.py.orig	2025-04-30 13:49:55 UTC
+++ setup.py
@@ -63,7 +63,7 @@ INSTALL_REQUIRES = (
 }
 
 INSTALL_REQUIRES = (
-    "protobuf>=6.30.0,<7.0dev",
+    "protobuf>=5.26.1,<7.0dev",
     "grpcio>={version}".format(version=grpc_version.VERSION),
     "googleapis-common-protos>=1.5.5",
 )
