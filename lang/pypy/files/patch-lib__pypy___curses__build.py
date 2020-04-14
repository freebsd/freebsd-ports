--- lib_pypy/_curses_build.py.orig	2020-03-25 12:13:59 UTC
+++ lib_pypy/_curses_build.py
@@ -31,6 +31,8 @@ def find_curses_dir_and_name():
             return base, 'ncursesw'
         if os.path.exists(os.path.join(base, 'include', 'ncurses')):
             return base, 'ncurses'
+        if os.path.exists(os.path.join(base, 'lib', 'libncursesw.so')):
+            return base, 'ncursesw'
     return '', None
 
 base, name = find_curses_dir_and_name()
