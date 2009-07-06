--- setup.py.orig	2009-06-28 20:59:53.170127518 +0800
+++ setup.py	2009-06-29 01:19:05.592053355 +0800
@@ -16,7 +16,7 @@
 from distutils.command.install_lib import install_lib
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_sqlite3", "_tkinter", "_gdbm"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -514,7 +514,7 @@
 
             readline_libs = ['readline']
             if self.compiler.find_library_file(lib_dirs,
-                                                 'ncursesw'):
+                                                 'XXXncursesw'):
                 readline_libs.append('ncursesw')
             elif self.compiler.find_library_file(lib_dirs,
                                                  'ncurses'):
@@ -526,7 +526,7 @@
                                                'termcap'):
                 readline_libs.append('termcap')
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib', '/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         else:
@@ -619,6 +619,8 @@
             # OpenSSL doesn't do these until 0.9.8 so we'll bring our own hash
             exts.append( Extension('_sha256', ['sha256module.c']) )
             exts.append( Extension('_sha512', ['sha512module.c']) )
+        else:
+            open('.without_own_sha', 'w')
 
         if openssl_ver < 0x00907000:
             # no openssl at all, use our own md5 and sha1
@@ -994,7 +996,7 @@
         # Curses support, requiring the System V version of curses, often
         # provided by the ncurses library.
         panel_library = 'panel'
-        if (self.compiler.find_library_file(lib_dirs, 'ncursesw')):
+        if (self.compiler.find_library_file(lib_dirs, 'XXXncursesw')):
             curses_libs = ['ncursesw']
             # Bug 1464056: If _curses.so links with ncursesw,
             # _curses_panel.so must link with panelw.
@@ -1004,6 +1006,7 @@
         elif (self.compiler.find_library_file(lib_dirs, 'ncurses')):
             curses_libs = ['ncurses']
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         elif (self.compiler.find_library_file(lib_dirs, 'curses')
               and platform != 'darwin'):
@@ -1025,6 +1028,7 @@
         if (module_enabled(exts, '_curses') and
             self.compiler.find_library_file(lib_dirs, panel_library)):
             exts.append( Extension('_curses_panel', ['_curses_panel.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = [panel_library] + curses_libs) )
         else:
             missing.append('_curses_panel')
@@ -1666,8 +1670,7 @@
           # called unless there's at least one extension module defined.
           ext_modules=[Extension('_struct', ['_struct.c'])],
 
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
-                     "Tools/scripts/2to3"]
+          scripts = []
         )
 
 # --install-platlib
