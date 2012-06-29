--- py/_path/local.py~	2012-06-22 12:20:36.000000000 +0200
+++ py/_path/local.py	2012-06-22 12:21:45.000000000 +0200
@@ -516,6 +516,9 @@
             pkgpath = self.pypkgpath()
             if pkgpath is not None:
                 if ensuresyspath:
+                    import sys
+                    if pkgpath.basename in sys.modules:
+                        del sys.modules[pkgpath.basename]
                     self._prependsyspath(pkgpath.dirpath())
                 pkg = __import__(pkgpath.basename, None, None, [])
                 names = self.new(ext='').relto(pkgpath.dirpath())
