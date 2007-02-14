--- setup.py.orig	Mon Nov 27 03:33:44 2006
+++ setup.py	Mon Nov 27 03:35:40 2006
@@ -15,7 +15,7 @@
 from distutils.command.install_lib import install_lib
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_bsddb", "_tkinter", "gdbm", "mpz"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -442,7 +442,7 @@
         if self.compiler.find_library_file(lib_dirs, 'readline'):
             readline_libs = ['readline']
             if self.compiler.find_library_file(lib_dirs,
-                                                 'ncursesw'):
+                                                 'xxxncursesw'):
                 readline_libs.append('ncursesw')
             elif self.compiler.find_library_file(lib_dirs,
                                                  'ncurses'):
@@ -728,7 +728,7 @@
         # Curses support, requiring the System V version of curses, often
         # provided by the ncurses library.
         panel_library = 'panel'
-        if (self.compiler.find_library_file(lib_dirs, 'ncursesw')):
+        if (self.compiler.find_library_file(lib_dirs, 'xxxncursesw')):
             curses_libs = ['ncursesw']
             # Bug 1464056: If _curses.so links with ncursesw,
             # _curses_panel.so must link with panelw.
