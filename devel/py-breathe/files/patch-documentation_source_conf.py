diff -u documentation/source/conf.py.orig b/documentation/source/conf.py
--- documentation/source/conf.py.orig	2026-04-26 08:35:23 UTC
+++ documentation/source/conf.py
@@ -22,6 +22,7 @@
 extensions = [
     "breathe",
     "sphinx.ext.graphviz",
+    "sphinx.ext.imgconverter",
     "sphinx_copybutton",
     "sphinxcontrib.spelling",
 ]
@@ -37,12 +38,12 @@
     version = release = "compare"
 else:
     # Get a description of the current position.
-    git_tag = subprocess.run(["git", "describe", "--tags"], capture_output=True, encoding="utf-8")
-    if re.match(r"^v\d+\.\d+\.\d+$", git_tag.stdout):
+    git_tag = "%%VERSION%%"
+    if re.match(r"^v\d+\.\d+\.\d+$", git_tag):
         # Check if it matches a pure tag number vX.Y.Z,
         # rather than vX.Y.Z-91-g8676988, which is how non-tagged commits
         # are described (relative to the last tag).
-        version = release = git_tag.stdout
+        version = release = git_tag
     else:
         version = release = "latest"
 
