--- configure.ac.orig	2018-11-09 11:03:00 UTC
+++ configure.ac
@@ -931,7 +931,7 @@ case "$host_os" in
 darwin*)
     ;;
 *)
-    AC_CHECK_FUNCS([clock_gettime], [CLOCK_LIB=],
+    AC_CHECK_FUNCS([clock_gettime clock_nanosleep], [CLOCK_LIB=],
                    [AC_CHECK_LIB([rt], [clock_gettime], [CLOCK_LIB=-lrt],
                                  [AC_MSG_ERROR([Could not find clock_gettime])])])
     AC_SUBST([CLOCK_LIB])
@@ -982,8 +982,12 @@ save_LIBS="$LIBS"
 LIBS="$PTHREAD_LIBS"
 AC_MSG_CHECKING(whether pthread_setaffinity_np is supported)
 AC_LINK_IFELSE([AC_LANG_SOURCE([[
+    #if  defined(__DragonFly__) || defined(__FreeBSD__)
+    #include <pthread_np.h>
+    #else
     #define _GNU_SOURCE
     #include <pthread.h>
+    #endif
     int main() {
        void *a = (void*) &pthread_setaffinity_np;
        long b = (long) a;
@@ -995,7 +999,10 @@ AC_LINK_IFELSE([AC_LANG_SOURCE([[
 LIBS="$save_LIBS"
 
 dnl Check for futex for fast inline simple_mtx_t.
-AC_CHECK_HEADER([linux/futex.h], [DEFINES="$DEFINES -DHAVE_LINUX_FUTEX_H"])
+AC_CHECK_HEADERS([linux/futex.h sys/umtx.h],
+    [DEFINES="$DEFINES -DHAVE_LINUX_FUTEX_H"],,
+    [#include <errno.h>
+     #include <sys/types.h>])
 
 dnl SELinux awareness.
 AC_ARG_ENABLE([selinux],
@@ -1278,7 +1285,7 @@ fi
 AC_SUBST(LIBSENSORS_LIBS)
 
 case "$host_os" in
-linux*)
+linux* | freebsd*)
     dri3_default=yes
     ;;
 *)
@@ -1932,9 +1939,9 @@ fi
 
 if test x"$have_xlease" = xyes; then
     randr_modules="x11-xcb xcb-randr"
-    PKG_CHECK_MODULES([XCB_RANDR], [$randr_modules])
+    PKG_CHECK_MODULES([XCB_RANDR], [$randr_modules],, [have_xlease=no])
     xlib_randr_modules="xrandr"
-    PKG_CHECK_MODULES([XLIB_RANDR], [$xlib_randr_modules])
+    PKG_CHECK_MODULES([XLIB_RANDR], [$xlib_randr_modules],, [have_xlease=no])
 fi
 
 AM_CONDITIONAL(HAVE_PLATFORM_X11, echo "$platforms" | grep -q 'x11')
@@ -2515,8 +2522,6 @@ if test "x$enable_opencl" = xyes; then
         CLANG_LIBDIR=${LLVM_LIBDIR}
     fi
     CLANG_RESOURCE_DIR=$CLANG_LIBDIR/clang/${LLVM_VERSION}
-    AS_IF([test ! -f "$CLANG_RESOURCE_DIR/include/stddef.h"],
-        [AC_MSG_ERROR([Could not find clang internal header stddef.h in $CLANG_RESOURCE_DIR Use --with-clang-libdir to specify the correct path to the clang libraries.])])
 fi
 AM_CONDITIONAL(HAVE_CLOVER, test "x$enable_opencl" = xyes)
 AM_CONDITIONAL(HAVE_CLOVER_ICD, test "x$enable_opencl_icd" = xyes)
