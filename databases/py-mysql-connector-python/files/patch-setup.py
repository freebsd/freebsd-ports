--- setup.py.orig	2023-01-17 19:32:28 UTC
+++ setup.py
@@ -139,7 +139,7 @@ setup(
     ],
     ext_modules=EXTENSIONS,
     cmdclass=COMMAND_CLASSES,
-    install_requires=["protobuf>=3.11.0,<=3.20.1"],
+    install_requires=["protobuf>=3.11.0"],
     extras_require={
         "dns-srv": ["dnspython>=1.16.0,<=2.1.0"],
         "compression": ["lz4>=2.1.6,<=3.1.3", "zstandard>=0.12.0,<=0.15.2"],
