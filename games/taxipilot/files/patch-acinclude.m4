--- admin/acinclude.m4.in.orig	Thu Nov 20 19:35:08 2003
+++ admin/acinclude.m4.in	Thu Nov 20 19:35:27 2003
@@ -2937,7 +2937,7 @@
    AC_REQUIRE([AC_FUNC_ALLOCA])dnl
    AC_REQUIRE([AC_FUNC_MMAP])dnl
    AC_REQUIRE([AM_KDE_WITH_NLS])dnl
-   AC_CHECK_HEADERS([argz.h limits.h locale.h nl_types.h string.h values.h alloca.h])
+   AC_CHECK_HEADERS([argz.h limits.h locale.h nl_types.h string.h values.h alloca.h stdint.h])
    AC_CHECK_FUNCS([getcwd munmap putenv setenv setlocale strchr strcasecmp \
 __argz_count __argz_stringify __argz_next])
 
