--- setup.py.orig	2023-01-18 12:48:13 UTC
+++ setup.py
@@ -139,7 +139,7 @@ if using_sphinx:
     build.sub_commands.insert(0, ("build_sphinx_man", None))
     cmdclass["build_sphinx_man"] = BuildDoc
 
-    if platform.system() in ("FreeBSD", "OpenBSD"):
+    if platform.system() in ("OpenBSD"):
         man_dir = "man"
     else:
         man_dir = "share/man"
