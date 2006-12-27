--- setup.py.orig	Mon Dec 25 09:20:34 2006
+++ setup.py	Mon Dec 25 09:20:44 2006
@@ -54,8 +54,6 @@
   version=_version,
   packages=[_package],
   package_dir={_package: ""},
-  data_files=[(_data_target, ["ftputil.txt", "ftputil.html",
-                              "README.txt", "README.html"])],
   # metadata
   author="Stefan Schwarzer",
   author_email="sschwarzer@sschwarzer.net",
