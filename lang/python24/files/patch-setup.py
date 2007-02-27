--- setup.py.orig	Tue Feb 27 20:10:53 2007
+++ setup.py	Tue Feb 27 20:15:23 2007
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
@@ -465,7 +465,7 @@
                 readline_extra_link_args = ()
 
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib', '/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         if platform not in ['mac']:
@@ -728,7 +728,7 @@
         # Curses support, requiring the System V version of curses, often
         # provided by the ncurses library.
         panel_library = 'panel'
-        if (self.compiler.find_library_file(lib_dirs, 'ncursesw')):
+        if (self.compiler.find_library_file(lib_dirs, 'xxxncursesw')):
             curses_libs = ['ncursesw']
             # Bug 1464056: If _curses.so links with ncursesw,
             # _curses_panel.so must link with panelw.
@@ -738,6 +738,7 @@
         elif (self.compiler.find_library_file(lib_dirs, 'ncurses')):
             curses_libs = ['ncurses']
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         elif (self.compiler.find_library_file(lib_dirs, 'curses')
               and platform != 'darwin'):
@@ -757,6 +758,7 @@
         if (module_enabled(exts, '_curses') and
             self.compiler.find_library_file(lib_dirs, panel_library)):
             exts.append( Extension('_curses_panel', ['_curses_panel.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = [panel_library] + curses_libs) )
 
 
