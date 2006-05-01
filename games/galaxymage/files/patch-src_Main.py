--- src/Main.py	Mon Jan 30 20:14:31 2006
+++ src/Main.py	Mon Jan 30 20:15:46 2006
@@ -44,14 +44,14 @@
     """Return the GalaxyMage version number."""
     global _version
     if _version == "":
-        f = file(os.path.join("doc", 'version.txt'), "rU")
+        f = file(os.path.join("%%DOCSDIR%%", 'version.txt'), "rU")
         _version = f.read().strip()
         f.close()
     return _version
     
 def printDoc(filename):
     """Print out the given file from the doc/ directory."""
-    f = file(os.path.join("doc", filename + '.txt'), "rU")
+    f = file(os.path.join("%%DOCSDIR%%", filename + '.txt'), "rU")
     text = f.read()
     print text,
     f.close()
