--- lib/python/ctypes/ctypesgencore/parser/preprocessor.py.orig	2016-11-04 UTC
+++ lib/python/ctypes/ctypesgencore/parser/preprocessor.py
@@ -150,6 +150,7 @@ class PreprocessorParser(object):
         if sys.platform == 'darwin':
             cmd += " -U __BLOCKS__"
         cmd += " -U __GNUC__"
+        cmd += " -D __GNUCLIKE_BUILTIN_STDARG"
         cmd += " -dD"
         for path in self.options.include_search_paths:
             cmd += " -I%s" % path
