--- setup.py.orig	2013-05-15 18:33:58.000000000 +0200
+++ setup.py	2014-07-27 11:00:57.000000000 +0200
@@ -21,7 +21,7 @@
 COMPILED_WITH_PYDEBUG = hasattr(sys, 'gettotalrefcount')
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_sqlite3", "_tkinter", "_gdbm"]
 
 # File which contains the directory for shared mods (for sys.path fixup
 # when running from the build dir, see Modules/getpath.c)
@@ -235,8 +235,8 @@
         # unfortunately, distutils doesn't let us provide separate C and C++
         # compilers
         if compiler is not None:
-            (ccshared,cflags) = sysconfig.get_config_vars('CCSHARED','CFLAGS')
-            args['compiler_so'] = compiler + ' ' + ccshared + ' ' + cflags
+            (ccshared,opt,cflags) = sysconfig.get_config_vars('CCSHARED','OPT','CFLAGS')
+            args['compiler_so'] = compiler + ' ' + ccshared + ' ' + opt + ' ' + cflags
         self.compiler.set_executables(**args)
 
         # Not only do we write the builddir cookie, but we manually install
@@ -668,7 +668,7 @@
                                                      'termcap'):
                 readline_libs.append('termcap')
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib','/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         else:
@@ -1373,7 +1373,7 @@
             macros = dict()
             libraries = []
 
-        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif platform in ('freebsd7', 'freebsd8', 'freebsd9', 'freebsd10', 'freebsd11'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
             macros = dict()
@@ -1416,9 +1416,12 @@
         # End multiprocessing
 
         # Platform-specific libraries
-        if (platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6',
-                        'freebsd7', 'freebsd8')
-            or platform.startswith("gnukfreebsd")):
+        #############################
+        # Backport Commit: http://hg.python.org/cpython/rev/50f1922bc1d5
+        # Backport Issue: http://bugs.python.org/issue12326
+        #############################
+        if any(platform.startswith(prefix)
+               for prefix in ("linux", "freebsd", "gnukfreebsd")):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
         else:
             missing.append('ossaudiodev')
@@ -1443,6 +1446,18 @@
         if '_tkinter' not in [e.name for e in self.extensions]:
             missing.append('_tkinter')
 
+        #############################
+        # Backport Commit: http://hg.python.org/cpython/rev/e5607874e8ff
+        # Backport Issue: http://bugs.python.org/issue18517
+        #############################
+##         # Uncomment these lines if you want to play with xxmodule.c
+##         ext = Extension('xx', ['xxmodule.c'])
+##         self.extensions.append(ext)
+        if 'd' not in sys.abiflags:
+            ext = Extension('xxlimited', ['xxlimited.c'],
+                            define_macros=[('Py_LIMITED_API', 1)])
+            self.extensions.append(ext)
+
         return missing
 
     def detect_tkinter_darwin(self, inc_dirs, lib_dirs):
@@ -1641,14 +1656,6 @@
                         )
         self.extensions.append(ext)
 
-##         # Uncomment these lines if you want to play with xxmodule.c
-##         ext = Extension('xx', ['xxmodule.c'])
-##         self.extensions.append(ext)
-        if 'd' not in sys.abiflags:
-            ext = Extension('xxlimited', ['xxlimited.c'],
-                            define_macros=[('Py_LIMITED_API', 1)])
-            self.extensions.append(ext)
-
         # XXX handle these, but how to detect?
         # *** Uncomment and edit for PIL (TkImaging) extension only:
         #       -DWITH_PIL -I../Extensions/Imaging/libImaging  tkImaging.c \
