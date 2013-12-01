--- ./setup.py.orig	2013-05-16 02:33:58.000000000 +1000
+++ ./setup.py	2013-12-01 21:08:17.425989640 +1100
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
@@ -629,7 +629,7 @@
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(lib_dirs, 'ncursesw'):
+        elif self.compiler.find_library_file(lib_dirs, 'XXXncursesw'):
             curses_library = 'ncursesw'
         elif self.compiler.find_library_file(lib_dirs, 'ncurses'):
             curses_library = 'ncurses'
@@ -668,7 +668,7 @@
                                                      'termcap'):
                 readline_libs.append('termcap')
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib','/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         else:
@@ -1187,12 +1187,13 @@
         # provided by the ncurses library.
         panel_library = 'panel'
         if curses_library.startswith('ncurses'):
-            if curses_library == 'ncursesw':
+            if curses_library == 'XXXncursesw':
                 # Bug 1464056: If _curses.so links with ncursesw,
                 # _curses_panel.so must link with panelw.
                 panel_library = 'panelw'
             curses_libs = [curses_library]
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                  library_dirs = ['/usr/lib'], 
                                    libraries = curses_libs) )
         elif curses_library == 'curses' and platform != 'darwin':
                 # OSX has an old Berkeley curses, not good enough for
@@ -1205,6 +1206,7 @@
                 curses_libs = ['curses']
 
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         else:
             missing.append('_curses')
@@ -1373,7 +1375,7 @@
             macros = dict()
             libraries = []
 
-        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif platform in ('freebsd7', 'freebsd8', 'freebsd9', 'freebsd10'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
             macros = dict()
@@ -1416,9 +1418,12 @@
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
@@ -1935,8 +1940,7 @@
           # If you change the scripts installed here, you also need to
           # check the PyBuildScripts command above, and change the links
           # created by the bininstall target in Makefile.pre.in
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
-                     "Tools/scripts/2to3"]
+          scripts = []
         )
 
 # --install-platlib
