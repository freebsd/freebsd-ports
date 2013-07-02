--- gnatlib/aclocal.m4.orig	2012-09-13 12:50:01.000000000 +0000
+++ gnatlib/aclocal.m4
@@ -643,7 +643,7 @@ AC_HELP_STRING(
             ia64-*hp-hpux11* )
                PYTHON_LIBS="-ldld -ldl -lm -Wl,-E ${PYTHON_LIBS}"
                ;;
-            *-freebsd* )
+            *-dragonfly* | *-freebsd* | *-netbsd* | *-openbsd* )
                PYTHON_LIBS="-lm -lutil ${PYTHON_LIBS}"
                ;;
          esac
