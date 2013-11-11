--- ./setup.py.orig	2012-09-29 18:00:50.000000000 +1000
+++ ./setup.py	2012-10-04 20:21:15.000000000 +1000
@@ -31,7 +31,7 @@
 COMPILED_WITH_PYDEBUG = ('--with-pydebug' in sysconfig.get_config_var("CONFIG_ARGS"))
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_sqlite3", "_tkinter", "_gdbm"]
 
 # File which contains the directory for shared mods (for sys.path fixup
 # when running from the build dir, see Modules/getpath.c)
@@ -694,7 +694,7 @@
         # use the same library for the readline and curses modules.
         if 'curses' in readline_termcap_library:
             curses_library = readline_termcap_library
-        elif self.compiler.find_library_file(lib_dirs, 'ncursesw'):
+        elif self.compiler.find_library_file(lib_dirs, 'XXXXncursesw'):
             curses_library = 'ncursesw'
         elif self.compiler.find_library_file(lib_dirs, 'ncurses'):
             curses_library = 'ncurses'
@@ -733,7 +733,7 @@
                                                      'termcap'):
                 readline_libs.append('termcap')
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib','/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         else:
@@ -1261,7 +1261,7 @@
         curses_defines = []
         curses_includes = []
         panel_library = 'panel'
-        if curses_library == 'ncursesw':
+        if curses_library == 'XXXXncursesw':
             curses_defines.append(('HAVE_NCURSESW', '1'))
             curses_includes.append('/usr/include/ncursesw')
             # Bug 1464056: If _curses.so links with ncursesw,
@@ -1285,6 +1285,7 @@
             exts.append( Extension('_curses', ['_cursesmodule.c'],
                                    include_dirs=curses_includes,
                                    define_macros=curses_defines,
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         elif curses_library == 'curses' and host_platform != 'darwin':
                 # OSX has an old Berkeley curses, not good enough for
@@ -1298,6 +1299,7 @@
 
             exts.append( Extension('_curses', ['_cursesmodule.c'],
                                    define_macros=curses_defines,
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         else:
             missing.append('_curses')
@@ -1462,7 +1464,7 @@
             macros = dict()
             libraries = []
 
-        elif host_platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif host_platform in ('freebsd7', 'freebsd8', 'freebsd9', 'freebsd10', 'freebsd11'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
             macros = dict()
@@ -2143,8 +2145,7 @@
           # If you change the scripts installed here, you also need to
           # check the PyBuildScripts command above, and change the links
           # created by the bininstall target in Makefile.pre.in
-          scripts = ["Tools/scripts/pydoc3", "Tools/scripts/idle3",
-                     "Tools/scripts/2to3", "Tools/scripts/pyvenv"]
+          scripts = []
         )
 
 # --install-platlib
