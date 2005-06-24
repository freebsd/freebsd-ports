--- ./setup.py	Fri Jun 24 15:10:27 2005
+++ ./setup.py.update	Fri Jun 24 15:12:28 2005
@@ -8,6 +8,6 @@
       url = "http://ljcharm.sourceforge.net",
       py_modules = ["ljcharm"],
       scripts = ["charm"],
-      data_files = [ ("share/doc/charm", ["charm.html", "sample.charmrc"]),
-                     ("share/man/man1", ["charm.1"]),
-                     ("share/man/man5", ["charmrc.5"]) ] )
+      data_files = [ ("share/doc/charm", ["charm.html"]),
+                     ("man/man1", ["charm.1"]),
+                     ("man/man5", ["charmrc.5"]) ] )
