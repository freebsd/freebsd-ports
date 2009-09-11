--- setup.py.orig	2009-03-31 18:20:48.000000000 +0000
+++ setup.py	2009-09-10 05:27:01.000000000 +0000
@@ -17,7 +17,7 @@ from distutils.command.install import in
 from distutils.command.install_lib import install_lib
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_bsddb", "_sqlite3", "_tkinter", "gdbm", "mpz"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -577,7 +577,7 @@ class PyBuildExt(build_ext):
 
             readline_libs = ['readline']
             if self.compiler.find_library_file(lib_dirs,
-                                                 'ncursesw'):
+                                                 'xxxncursesw'):
                 readline_libs.append('ncursesw')
             elif self.compiler.find_library_file(lib_dirs,
                                                  'ncurses'):
@@ -589,7 +589,7 @@ class PyBuildExt(build_ext):
                                                'termcap'):
                 readline_libs.append('termcap')
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib', '/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         else:
@@ -689,6 +689,8 @@ class PyBuildExt(build_ext):
             # OpenSSL doesn't do these until 0.9.8 so we'll bring our own hash
             exts.append( Extension('_sha256', ['sha256module.c']) )
             exts.append( Extension('_sha512', ['sha512module.c']) )
+        else:
+            open('.without_own_sha', 'w')
 
         # Modules that provide persistent dictionary-like semantics.  You will
         # probably want to arrange for at least one of them to be available on
@@ -990,7 +992,7 @@ class PyBuildExt(build_ext):
         # the more recent berkeleydb's db.h file first in the include path
         # when attempting to compile and it will fail.
         f = "/usr/include/db.h"
-        if os.path.exists(f) and not db_incs:
+        if os.path.exists(f):
             data = open(f).read()
             m = re.search(r"#s*define\s+HASHVERSION\s+2\s*", data)
             if m is not None:
@@ -1080,7 +1082,7 @@ class PyBuildExt(build_ext):
         # Curses support, requiring the System V version of curses, often
         # provided by the ncurses library.
         panel_library = 'panel'
-        if (self.compiler.find_library_file(lib_dirs, 'ncursesw')):
+        if (self.compiler.find_library_file(lib_dirs, 'xxxncursesw')):
             curses_libs = ['ncursesw']
             # Bug 1464056: If _curses.so links with ncursesw,
             # _curses_panel.so must link with panelw.
@@ -1090,6 +1092,7 @@ class PyBuildExt(build_ext):
         elif (self.compiler.find_library_file(lib_dirs, 'ncurses')):
             curses_libs = ['ncurses']
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         elif (self.compiler.find_library_file(lib_dirs, 'curses')
               and platform != 'darwin'):
@@ -1111,6 +1114,7 @@ class PyBuildExt(build_ext):
         if (module_enabled(exts, '_curses') and
             self.compiler.find_library_file(lib_dirs, panel_library)):
             exts.append( Extension('_curses_panel', ['_curses_panel.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = [panel_library] + curses_libs) )
         else:
             missing.append('_curses_panel')
@@ -1273,7 +1277,7 @@ class PyBuildExt(build_ext):
                 )
             libraries = []
 
-        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8', 'freebsd9'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
             macros = dict(                  # FreeBSD
@@ -1338,7 +1342,7 @@ class PyBuildExt(build_ext):
             missing.append('linuxaudiodev')
 
         if platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6',
-                        'freebsd7', 'freebsd8'):
+                        'freebsd7', 'freebsd8', 'freebsd9'):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
         else:
             missing.append('ossaudiodev')
@@ -1891,9 +1895,7 @@ def main():
           ext_modules=[Extension('_struct', ['_struct.c'])],
 
           # Scripts to install
-          scripts = ['Tools/scripts/pydoc', 'Tools/scripts/idle',
-                     'Tools/scripts/2to3',
-                     'Lib/smtpd.py']
+          scripts = []
         )
 
 # --install-platlib
