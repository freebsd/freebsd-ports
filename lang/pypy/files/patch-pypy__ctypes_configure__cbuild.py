--- ctypes_configure/cbuild.py~	2011-11-19 09:44:54.000000000 +0200
+++ ctypes_configure/cbuild.py	2011-11-23 21:47:02.000000000 +0200
@@ -199,13 +199,14 @@
     #except ImportError:
     #    print "ERROR IMPORTING"
     #    pass
+    from pypy.translator.platform import platform
     cfiles = [py.path.local(f) for f in cfiles]
     if tmpdir is None:
         tmpdir = configdir.join("module_cache").ensure(dir=1)
     num = 0
     cfiles += eci.separate_module_files
-    include_dirs = list(eci.include_dirs)
-    library_dirs = list(eci.library_dirs)
+    include_dirs = platform.preprocess_include_dirs(eci.include_dirs)
+    library_dirs = platform.preprocess_library_dirs(eci.library_dirs)
     if sys.platform == 'darwin':    # support Fink & Darwinports
         for s in ('/sw/', '/opt/local/'):
             if s + 'include' not in include_dirs and \
@@ -362,13 +363,14 @@
 
     def __init__(self, cfilenames, eci, outputfilename=None,
                  compiler_exe=None, profbased=None):
+        from pypy.translator.platform import platform
         self.cfilenames = cfilenames
         ext = ''
         self.compile_extra = []
         self.link_extra = []
         self.libraries = list(eci.libraries)
-        self.include_dirs = list(eci.include_dirs)
-        self.library_dirs = list(eci.library_dirs)
+        self.include_dirs = platform.preprocess_include_dirs(eci.include_dirs)
+        self.library_dirs = platform.preprocess_library_dirs(eci.library_dirs)
         self.compiler_exe = compiler_exe
         self.profbased = profbased
         if not sys.platform in ('win32', 'darwin'): # xxx
@@ -436,7 +438,7 @@
             old = cfile.dirpath().chdir() 
             try: 
                 res = compiler.compile([cfile.basename], 
-                                       include_dirs=self.eci.include_dirs,
+                                       include_dirs=self.include_dirs,
                                        extra_preargs=self.compile_extra)
                 assert len(res) == 1
                 cobjfile = py.path.local(res[0]) 
@@ -445,9 +447,9 @@
             finally: 
                 old.chdir() 
         compiler.link_executable(objects, str(self.outputfilename),
-                                 libraries=self.eci.libraries,
+                                 libraries=self.libraries,
                                  extra_preargs=self.link_extra,
-                                 library_dirs=self.eci.library_dirs)
+                                 library_dirs=self.library_dirs)
 
 def build_executable(*args, **kwds):
     noerr = kwds.pop('noerr', False)
