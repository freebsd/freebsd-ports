--- setup.py.orig	2023-12-31 10:57:00 UTC
+++ setup.py
@@ -374,7 +374,7 @@ if sys.platform == "darwin" and sys.version_info < (3,
     install_requires.append("orderedset >= 2.0.3")
 
 setup(
-    name="Nuitka",
+    name="nuitka",
     license="Apache License, Version 2.0",
     version=version,
     long_description=long_description,
