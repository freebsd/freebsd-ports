--- setup.py.orig	2008-09-30 09:15:45.000000000 +0900
+++ setup.py	2008-10-09 20:34:35.000000000 +0900
@@ -17,7 +17,7 @@
 from distutils.command.install_lib import install_lib
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_sqlite3", "_tkinter", "_gdbm"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -575,7 +575,7 @@
 
             readline_libs = ['readline']
             if self.compiler.find_library_file(lib_dirs,
-                                                 'ncursesw'):
+                                                 'xxxncursesw'):
                 readline_libs.append('ncursesw')
             elif self.compiler.find_library_file(lib_dirs,
                                                  'ncurses'):
@@ -587,7 +587,7 @@
                                                'termcap'):
                 readline_libs.append('termcap')
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib', '/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         else:
@@ -687,6 +687,8 @@
             # OpenSSL doesn't do these until 0.9.8 so we'll bring our own hash
             exts.append( Extension('_sha256', ['sha256module.c']) )
             exts.append( Extension('_sha512', ['sha512module.c']) )
+        else:
+            open('.without_own_sha', 'w')
 
         # Modules that provide persistent dictionary-like semantics.  You will
         # probably want to arrange for at least one of them to be available on
@@ -1066,7 +1068,7 @@
         # Curses support, requiring the System V version of curses, often
         # provided by the ncurses library.
         panel_library = 'panel'
-        if (self.compiler.find_library_file(lib_dirs, 'ncursesw')):
+        if (self.compiler.find_library_file(lib_dirs, 'xxxncursesw')):
             curses_libs = ['ncursesw']
             # Bug 1464056: If _curses.so links with ncursesw,
             # _curses_panel.so must link with panelw.
@@ -1076,6 +1078,7 @@
         elif (self.compiler.find_library_file(lib_dirs, 'ncurses')):
             curses_libs = ['ncurses']
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         elif (self.compiler.find_library_file(lib_dirs, 'curses')
               and platform != 'darwin'):
@@ -1097,6 +1100,7 @@
         if (module_enabled(exts, '_curses') and
             self.compiler.find_library_file(lib_dirs, panel_library)):
             exts.append( Extension('_curses_panel', ['_curses_panel.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = [panel_library] + curses_libs) )
         else:
             missing.append('_curses_panel')
@@ -1869,9 +1873,7 @@
           ext_modules=[Extension('_struct', ['_struct.c'])],
 
           # Scripts to install
-          scripts = ['Tools/scripts/pydoc', 'Tools/scripts/idle',
-                     'Tools/scripts/2to3',
-                     'Lib/smtpd.py']
+          scripts = []
         )
 
 # --install-platlib
