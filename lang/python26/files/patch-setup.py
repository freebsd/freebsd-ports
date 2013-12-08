--- ./setup.py.orig	2013-10-30 02:04:39.000000000 +1100
+++ ./setup.py	2013-12-08 18:42:28.054900011 +1100
@@ -18,7 +18,7 @@
 from distutils.spawn import find_executable
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_bsddb", "_sqlite3", "_tkinter", "gdbm", "mpz"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -627,7 +627,7 @@
         #    curses_library = readline_termcap_library
         # elif self.compiler.find_library_file(lib_dirs, 'ncursesw'):
         # (...)
-        if self.compiler.find_library_file(lib_dirs, 'ncursesw'):
+        if self.compiler.find_library_file(lib_dirs, 'xxxncursesw'):
             curses_library = 'ncursesw'
         elif self.compiler.find_library_file(lib_dirs, 'ncurses'):
             curses_library = 'ncurses'
@@ -666,7 +666,7 @@
                                                'termcap'):
                 readline_libs.append('termcap')
             exts.append( Extension('readline', ['readline.c'],
-                                   library_dirs=['/usr/lib/termcap'],
+                                   library_dirs=['/usr/lib','/usr/lib/termcap'],
                                    extra_link_args=readline_extra_link_args,
                                    libraries=readline_libs) )
         else:
@@ -766,6 +766,8 @@
             # OpenSSL doesn't do these until 0.9.8 so we'll bring our own hash
             exts.append( Extension('_sha256', ['sha256module.c']) )
             exts.append( Extension('_sha512', ['sha512module.c']) )
+        else:
+            open('.without_own_sha', 'w')
 
         # Modules that provide persistent dictionary-like semantics.  You will
         # probably want to arrange for at least one of them to be available on
@@ -1101,7 +1103,7 @@
                 sysroot = macosx_sdk_root()
                 f = os.path.join(sysroot, f[1:])
 
-        if os.path.exists(f) and not db_incs:
+        if os.path.exists(f):
             data = open(f).read()
             m = re.search(r"#s*define\s+HASHVERSION\s+2\s*", data)
             if m is not None:
@@ -1193,12 +1195,13 @@
         # provided by the ncurses library.
         panel_library = 'panel'
         if curses_library.startswith('ncurses'):
-            if curses_library == 'ncursesw':
+            if curses_library == 'xxxncursesw':
                 # Bug 1464056: If _curses.so links with ncursesw,
                 # _curses_panel.so must link with panelw.
                 panel_library = 'panelw'
             curses_libs = [curses_library]
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         elif curses_library == 'curses' and platform != 'darwin':
                 # OSX has an old Berkeley curses, not good enough for
@@ -1211,6 +1214,7 @@
                 curses_libs = ['curses']
 
             exts.append( Extension('_curses', ['_cursesmodule.c'],
+                                   library_dirs = ['/usr/lib'],
                                    libraries = curses_libs) )
         else:
             missing.append('_curses')
@@ -1381,7 +1385,7 @@
                 )
             libraries = []
 
-        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8'):
+        elif platform in ('freebsd4', 'freebsd5', 'freebsd6', 'freebsd7', 'freebsd8', 'freebsd9', 'freebsd10', 'freebsd11'):
             # FreeBSD's P1003.1b semaphore support is very experimental
             # and has many known problems. (as of June 2008)
             macros = dict(                  # FreeBSD
@@ -1449,8 +1453,12 @@
         else:
             missing.append('linuxaudiodev')
 
-        if platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6',
-                        'freebsd7', 'freebsd8'):
+        #############################
+        # Backport Commit: http://hg.python.org/cpython/rev/50f1922bc1d5
+        # Backport Issue: http://bugs.python.org/issue12326
+        #############################
+        if any(platform.startswith(prefix)
+               for prefix in ("linux", "freebsd", "gnukfreebsd")):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
         else:
             missing.append('ossaudiodev')
@@ -2026,9 +2034,7 @@
           ext_modules=[Extension('_struct', ['_struct.c'])],
 
           # Scripts to install
-          scripts = ['Tools/scripts/pydoc', 'Tools/scripts/idle',
-                     'Tools/scripts/2to3',
-                     'Lib/smtpd.py']
+          scripts = []
         )
 
 # --install-platlib
