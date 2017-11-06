--- lib/python/ctypes/ctypesgencore/parser/preprocessor.py.orig
+++ lib/python/ctypes/ctypesgencore/parser/preprocessor.py
@@ -132,6 +132,7 @@
         if sys.platform == 'darwin':
             cmd += " -U __BLOCKS__"
         cmd += " -U __GNUC__"
+        cmd += " -D __GNUCLIKE_BUILTIN_STDARG"
         cmd += " -dD"
         for path in self.options.include_search_paths:
             cmd += " -I%s" % path 
