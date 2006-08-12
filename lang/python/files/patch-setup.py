--- setup.py.orig	Sat Aug 12 12:46:21 2006
+++ setup.py	Sat Aug 12 12:47:00 2006
@@ -15,7 +15,7 @@
 from distutils.command.install_lib import install_lib
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_bsddb", "_tkinter", "gdbm", "mpz"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -425,7 +425,7 @@
         if self.compiler.find_library_file(lib_dirs, 'readline'):
             readline_libs = ['readline']
             if self.compiler.find_library_file(lib_dirs,
-                                                 'ncursesw'):
+                                                 'xxxncursesw'):
                 readline_libs.append('ncursesw')
             elif self.compiler.find_library_file(lib_dirs,
                                                  'ncurses'):
@@ -681,7 +681,7 @@
 
         # Curses support, requiring the System V version of curses, often
         # provided by the ncurses library.
-        if (self.compiler.find_library_file(lib_dirs, 'ncursesw')):
+        if (self.compiler.find_library_file(lib_dirs, 'xxxncursesw')):
             curses_libs = ['ncursesw']
             exts.append( Extension('_curses', ['_cursesmodule.c'],
                                    libraries = curses_libs) )
