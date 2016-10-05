--- tools/ax_lib_readline.m4.orig	2016-08-11 02:38:59 UTC
+++ tools/ax_lib_readline.m4
@@ -33,17 +33,19 @@ _bash_needmsg=
 fi
 AC_CACHE_VAL(bash_cv_termcap_lib,
 [AC_CHECK_FUNC(tgetent, bash_cv_termcap_lib=libc,
-  [AC_CHECK_LIB(termcap, tgetent, bash_cv_termcap_lib=libtermcap,
-    [AC_CHECK_LIB(tinfo, tgetent, bash_cv_termcap_lib=libtinfo,
-        bash_cv_termcap_lib=gnutermcap
 if test "$ax_cv_curses_which" = "ncursesw"; then
         [AC_CHECK_LIB(ncursesw, tgetent, bash_cv_termcap_lib=libncursesw)]
 elif test "$ax_cv_curses_which" = "ncurses"; then
         [AC_CHECK_LIB(ncurses, tgetent, bash_cv_termcap_lib=libncurses)]
 elif test "$ax_cv_curses_which" = "plaincurses"; then
         [AC_CHECK_LIB(curses, tgetent, bash_cv_termcap_lib=libcurses)]
+else
+  [AC_CHECK_LIB(termcap, tgetent, bash_cv_termcap_lib=libtermcap,
+    [AC_CHECK_LIB(tinfo, tgetent, bash_cv_termcap_lib=libtinfo,
+        bash_cv_termcap_lib=gnutermcap
+  )])]
 fi
-)])])])
+)])
 if test "X$_bash_needmsg" = "Xyes"; then
 AC_MSG_CHECKING(which library has the termcap functions)
 fi
