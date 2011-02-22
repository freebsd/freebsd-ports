--- setup.py.orig	2010-12-28 17:51:43.000000000 +0800
+++ setup.py	2011-02-21 21:08:22.000000000 +0800
@@ -21,7 +21,7 @@
 COMPILED_WITH_PYDEBUG = hasattr(sys, 'gettotalrefcount')
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_sqlite3", "_tkinter", "_gdbm"]
 
 # File which contains the directory for shared mods (for sys.path fixup
 # when running from the build dir, see Modules/getpath.c)
@@ -585,7 +585,7 @@
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(lib_dirs, 'ncursesw'):
+        elif self.compiler.find_library_file(lib_dirs, 'XXXncursesw'):
             curses_library = 'ncursesw'
         elif self.compiler.find_library_file(lib_dirs, 'ncurses'):
             curses_library = 'ncurses'
@@ -624,7 +624,7 @@
                                                      'termcap'):
                 readline_libs.append('termcap')
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib','/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         else:
@@ -724,6 +724,8 @@
                                    depends=['hashlib.h']) )
             exts.append( Extension('_sha512', ['sha512module.c'],
                                    depends=['hashlib.h']) )
+        else:
+            open('.without_own_sha', 'w')
 
         if COMPILED_WITH_PYDEBUG or not have_usable_openssl:
             # no openssl at all, use our own md5 and sha1
@@ -1139,12 +1141,13 @@
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
@@ -1157,6 +1160,7 @@
                 curses_libs = ['curses']
 
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         else:
             missing.append('_curses')
@@ -1309,7 +1313,7 @@
             macros = dict()
             libraries = []
 
-        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif platform in ('freebsd7', 'freebsd8', 'freebsd9'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
             macros = dict()
@@ -1352,8 +1356,7 @@
         # End multiprocessing
 
         # Platform-specific libraries
-        if (platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6',
-                        'freebsd7', 'freebsd8')
+        if (platform in ('freebsd7', 'freebsd8', 'freebsd9')
             or platform.startswith("gnukfreebsd")):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
         else:
@@ -1868,8 +1871,7 @@
           # If you change the scripts installed here, you also need to
           # check the PyBuildScripts command above, and change the links
           # created by the bininstall target in Makefile.pre.in
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
-                     "Tools/scripts/2to3"]
+          scripts = []
         )
 
 # --install-platlib
