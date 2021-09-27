--- src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_pkgutil_old.py.orig	2021-09-26 20:08:06 UTC
+++ src/debugpy/_vendored/pydevd/_pydev_imps/_pydev_pkgutil_old.py
@@ -140,7 +140,7 @@ def iter_modules(path=None, prefix=''):
     if path is None:
         importers = iter_importers()
     else:
-        importers = map(get_importer, path)
+        importers = list(map(get_importer, path))
 
     yielded = {}
     for i in importers:
@@ -329,7 +329,7 @@ try:
     from zipimport import zipimporter
 
     def iter_zipimport_modules(importer, prefix=''):
-        dirlist = zipimport._zip_directory_cache[importer.archive].keys()
+        dirlist = list(zipimport._zip_directory_cache[importer.archive].keys())
         dirlist.sort()
         _prefix = importer.prefix
         plen = len(_prefix)
@@ -526,7 +526,7 @@ def extend_path(path, name):
     path = path[:] # Start with a copy of the existing path
 
     for dir in sys.path:
-        if not isinstance(dir, basestring) or not os.path.isdir(dir):
+        if not isinstance(dir, str) or not os.path.isdir(dir):
             continue
         subdir = os.path.join(dir, pname)
         # XXX This may still add duplicate entries to path on
@@ -540,7 +540,7 @@ def extend_path(path, name):
         if os.path.isfile(pkgfile):
             try:
                 f = open(pkgfile)
-            except IOError, msg:
+            except IOError as msg:
                 sys.stderr.write("Can't open %s: %s\n" %
                                  (pkgfile, msg))
             else:
