--- setup.py.orig	2020-07-15 20:17:08 UTC
+++ setup.py
@@ -16,7 +16,7 @@ setup(
     name="curtsies",
     version=version(),
     description="Curses-like terminal wrapper, with colored strings!",
-    long_description=open("readme.md", encoding="utf-8").read(),
+    long_description=io.open("readme.md", encoding="utf-8").read(),
     long_description_content_type="text/markdown",
     url="https://github.com/bpython/curtsies",
     author="Thomas Ballinger",
