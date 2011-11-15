--- gnatlib/aclocal.m4.orig	2010-07-19 10:57:13.000000000 +0200
+++ gnatlib/aclocal.m4	2011-10-11 03:05:28.000000000 +0200
@@ -452,6 +452,18 @@
           *-darwin* )
              PYTHON_LIBS="-ldl -lm ${PYTHON_LIBS}"
              ;;
+          *-freebsd* )
+             PYTHON_LIBS="-lm -lutil ${PYTHON_LIBS}"
+             ;;
+          *-dragonfly* )
+             PYTHON_LIBS="-lm -lutil ${PYTHON_LIBS}"
+             ;;
+          *-netbsd* )
+             PYTHON_LIBS="-lm -lutil ${PYTHON_LIBS}"
+             ;;
+          *-openbsd* )
+             PYTHON_LIBS="-lm -lutil ${PYTHON_LIBS}"
+             ;;
           x86_64-*-* )
              PYTHON_LIBS="-Wl,-export-dynamic -lm -ldl ${PYTHON_LIBS}"
              ;;
@@ -460,9 +472,6 @@
              ;;
           i[[3456]]86-*win32* | i[[3456]]86-*mingw32* | i[[3456]]86-*cygwin* )
              ;;
-          *-freebsd* )
-             PYTHON_LIBS="-lm -lutil ${PYTHON_LIBS}"
-             ;;
       esac
 
       if test -f ${PYTHON_DIR}/libpython${PYTHON_VERSION}.a ; then
