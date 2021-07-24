--- setup.py.orig	2021-07-15 00:12:15 UTC
+++ setup.py
@@ -34,6 +34,5 @@ setup(
             "protoc-gen-mypy_grpc = mypy_protobuf.main:grpc",
         ],
     },
-    scripts=["mypy_protobuf/protoc_gen_mypy.bat"],
     python_requires=">=3.6",
 )
