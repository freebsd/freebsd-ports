--- ply/lex.py.orig	2015-04-26 21:17:41 UTC
+++ ply/lex.py
@@ -171,7 +171,10 @@ class Lexer:
     # ------------------------------------------------------------
     # writetab() - Write lexer information to a table file
     # ------------------------------------------------------------
-    def writetab(self, basetabmodule, outputdir=''):
+    def writetab(self, lextab, outputdir=''):
+        if isinstance(lextab, types.ModuleType):
+            raise IOError("Won't overwrite existing lextab module")
+        basetabmodule = lextab.split('.')[-1]
         filename = os.path.join(outputdir, basetabmodule) + '.py'
         with open(filename, 'w') as tf:
             tf.write('# %s.py. This file automatically created by PLY (version %s). Don\'t edit!\n' % (basetabmodule, __version__))
@@ -856,6 +859,10 @@ class LexerReflect(object):
 # -----------------------------------------------------------------------------
 def lex(module=None, object=None, debug=False, optimize=False, lextab='lextab',
         reflags=0, nowarn=False, outputdir=None, debuglog=None, errorlog=None):
+
+    if lextab is None:
+        lextab = 'lextab'
+
     global lexer
 
     ldict = None
@@ -885,29 +892,13 @@ def lex(module=None, object=None, debug=
     else:
         ldict = get_caller_module_dict(2)
 
-    if outputdir is None:
-        # If no output directory is set, the location of the output files
-        # is determined according to the following rules:
-        #     - If lextab specifies a package, files go into that package directory
-        #     - Otherwise, files go in the same directory as the specifying module
-        if '.' not in lextab:
-            srcfile = ldict['__file__']
-        else:
-            parts = lextab.split('.')
-            pkgname = '.'.join(parts[:-1])
-            exec('import %s' % pkgname)
-            srcfile = getattr(sys.modules[pkgname], '__file__', '')
-        outputdir = os.path.dirname(srcfile)
-
     # Determine if the module is package of a package or not.
     # If so, fix the tabmodule setting so that tables load correctly
     pkg = ldict.get('__package__')
-    if pkg:
+    if pkg and isinstance(lextab, str):
         if '.' not in lextab:
             lextab = pkg + '.' + lextab
 
-    baselextab = lextab.split('.')[-1]
-
     # Collect parser information from the dictionary
     linfo = LexerReflect(ldict, log=errorlog, reflags=reflags)
     linfo.get_all()
@@ -1029,8 +1020,24 @@ def lex(module=None, object=None, debug=
 
     # If in optimize mode, we write the lextab
     if lextab and optimize:
+        if outputdir is None:
+            # If no output directory is set, the location of the output files
+            # is determined according to the following rules:
+            #     - If lextab specifies a package, files go into that package directory
+            #     - Otherwise, files go in the same directory as the specifying module
+            if isinstance(lextab, types.ModuleType):
+                srcfile = lextab.__file__
+            else:
+                if '.' not in lextab:
+                    srcfile = ldict['__file__']
+                else:
+                    parts = lextab.split('.')
+                    pkgname = '.'.join(parts[:-1])
+                    exec('import %s' % pkgname)
+                    srcfile = getattr(sys.modules[pkgname], '__file__', '')
+            outputdir = os.path.dirname(srcfile)
         try:
-            lexobj.writetab(baselextab, outputdir)
+            lexobj.writetab(lextab, outputdir)
         except IOError as e:
             errorlog.warning("Couldn't write lextab module %r. %s" % (lextab, e))
 
