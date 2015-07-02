--- ply/yacc.py.orig	2015-04-26 21:19:12 UTC
+++ ply/yacc.py
@@ -2692,7 +2692,11 @@ class LRGeneratedTable(LRTable):
     # This function writes the LR parsing tables to a file
     # -----------------------------------------------------------------------------
 
-    def write_table(self, basemodulename, outputdir='', signature=''):
+    def write_table(self, tabmodule, outputdir='', signature=''):
+        if isinstance(tabmodule, types.ModuleType):
+            raise IOError("Won't overwrite existing tabmodule")
+
+        basemodulename = tabmodule.split('.')[-1]
         filename = os.path.join(outputdir, basemodulename) + '.py'
         try:
             f = open(filename, 'w')
@@ -2705,7 +2709,7 @@ _tabversion = %r
 _lr_method = %r
 
 _lr_signature = %r
-    ''' % (filename, __tabversion__, self.lr_method, signature))
+    ''' % (os.path.basename(filename), __tabversion__, self.lr_method, signature))
 
             # Change smaller to 0 to go back to original tables
             smaller = 1
@@ -3179,6 +3183,9 @@ def yacc(method='LALR', debug=yaccdebug,
          check_recursion=True, optimize=False, write_tables=True, debugfile=debug_file,
          outputdir=None, debuglog=None, errorlog=None, picklefile=None):
 
+    if tabmodule is None:
+        tabmodule = tab_module
+
     # Reference to the parsing method of the last built parser
     global parse
 
@@ -3204,22 +3211,26 @@ def yacc(method='LALR', debug=yaccdebug,
         # is determined according to the following rules:
         #     - If tabmodule specifies a package, files go into that package directory
         #     - Otherwise, files go in the same directory as the specifying module
-        if '.' not in tabmodule:
-            srcfile = pdict['__file__']
+        if isinstance(tabmodule, types.ModuleType):
+            srcfile = tabmodule.__file__
         else:
-            parts = tabmodule.split('.')
-            pkgname = '.'.join(parts[:-1])
-            exec('import %s' % pkgname)
-            srcfile = getattr(sys.modules[pkgname], '__file__', '')
+            if '.' not in tabmodule:
+                srcfile = pdict['__file__']
+            else:
+                parts = tabmodule.split('.')
+                pkgname = '.'.join(parts[:-1])
+                exec('import %s' % pkgname)
+                srcfile = getattr(sys.modules[pkgname], '__file__', '')
         outputdir = os.path.dirname(srcfile)
 
     # Determine if the module is package of a package or not.
     # If so, fix the tabmodule setting so that tables load correctly
     pkg = pdict.get('__package__')
-    if pkg and '.' not in tabmodule:
-        tabmodule = pkg + '.' + tabmodule
+    if pkg and isinstance(tabmodule, str):
+        if '.' not in tabmodule:
+            tabmodule = pkg + '.' + tabmodule
+
 
-    basetabmodule = tabmodule.split('.')[-1]
 
     # Set start symbol if it's specified directly using an argument
     if start is not None:
@@ -3432,7 +3443,7 @@ def yacc(method='LALR', debug=yaccdebug,
     # Write the table file if requested
     if write_tables:
         try:
-            lr.write_table(basetabmodule, outputdir, signature)
+            lr.write_table(tabmodule, outputdir, signature)
         except IOError as e:
             errorlog.warning("Couldn't create %r. %s" % (tabmodule, e))
 
