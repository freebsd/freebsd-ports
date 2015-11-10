--- __pkginfo__.py.orig	2015-10-27 08:06:17 UTC
+++ __pkginfo__.py
@@ -28,7 +28,7 @@ web = 'https://github.com/rocky/pycolumn
 zip_safe = False
 
 def read(*rnames):
-    return open(os.path.join(os.path.dirname(__file__), *rnames)).read()
+    return open(os.path.join(os.path.dirname(__file__), *rnames), encoding='utf8').read()
 
 readme = 'README.txt'
 if os.path.exists('README.rst'): readme = 'README.rst'
