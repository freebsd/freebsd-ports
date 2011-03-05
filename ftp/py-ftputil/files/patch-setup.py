--- setup.py.orig	2010-08-14 13:22:25.000000000 +0400
+++ setup.py	2011-03-05 14:52:45.000000000 +0300
@@ -29,8 +29,6 @@
   version=_version,
   packages=[_package],
   package_dir={_package: ""},
-  data_files=[("doc/ftputil", ["ftputil.txt", "ftputil.html",
-                               "README.txt", "README.html"])],
   # Metadata
   author="Stefan Schwarzer",
   author_email="sschwarzer@sschwarzer.net",
