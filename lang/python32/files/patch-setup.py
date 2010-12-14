--- setup.py.orig	2010-11-26 19:56:26.000000000 +0800
+++ setup.py	2010-12-14 10:53:36.000000000 +0800
@@ -17,7 +17,7 @@
 from distutils.spawn import find_executable
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_sqlite3", "_tkinter", "_gdbm"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -578,7 +578,7 @@
         #    curses_library = readline_termcap_library
         # elif self.compiler.find_library_file(lib_dirs, 'ncursesw'):
         # (...)
-        if self.compiler.find_library_file(lib_dirs, 'ncursesw'):
+        if self.compiler.find_library_file(lib_dirs, 'XXXncursesw'):
             curses_library = 'ncursesw'
         elif self.compiler.find_library_file(lib_dirs, 'ncurses'):
             curses_library = 'ncurses'
@@ -614,7 +614,7 @@
                                                'termcap'):
                 readline_libs.append('termcap')
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib', '/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         else:
@@ -708,6 +708,8 @@
             # OpenSSL doesn't do these until 0.9.8 so we'll bring our own hash
             exts.append( Extension('_sha256', ['sha256module.c']) )
             exts.append( Extension('_sha512', ['sha512module.c']) )
+        else:
+            open('.without_own_sha', 'w')
 
         if openssl_ver < 0x00907000:
             # no openssl at all, use our own md5 and sha1
@@ -1116,12 +1118,13 @@
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
+				   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         elif curses_library == 'curses' and platform != 'darwin':
                 # OSX has an old Berkeley curses, not good enough for
@@ -1142,6 +1145,7 @@
         if (module_enabled(exts, '_curses') and
             self.compiler.find_library_file(lib_dirs, panel_library)):
             exts.append( Extension('_curses_panel', ['_curses_panel.c'],
+				   library_dirs = ['/usr/lib'],
                                    libraries = [panel_library] + curses_libs) )
         else:
             missing.append('_curses_panel')
@@ -1278,7 +1282,7 @@
             macros = dict()
             libraries = []
 
-        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif platform in ('freebsd6', 'freebsd7', 'freebsd8', 'freebsd9'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
             macros = dict()
@@ -1321,8 +1325,7 @@
         # End multiprocessing
 
         # Platform-specific libraries
-        if platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6',
-                        'freebsd7', 'freebsd8'):
+        if platform in ('linux2', 'freebsd6', 'freebsd7', 'freebsd8', 'freebsd9'):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
         else:
             missing.append('ossaudiodev')
@@ -1808,8 +1811,7 @@
           # called unless there's at least one extension module defined.
           ext_modules=[Extension('_struct', ['_struct.c'])],
 
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
-                     "Tools/scripts/2to3"]
+          scripts = []
         )
 
 # --install-platlib
