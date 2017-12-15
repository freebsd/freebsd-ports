--- lib_pypy/_curses_build.py.orig	2017-10-03 10:53:54 UTC
+++ lib_pypy/_curses_build.py
@@ -34,6 +34,8 @@ ffi.set_source("_curses_cffi", """
 #define NCURSES_OPAQUE 0
 #endif
 
+#define _XOPEN_SOURCE_EXTENDED 1
+#define NCURSES_WIDECHAR 1
 #include <ncurses.h>
 #include <panel.h>
 #include <term.h>
