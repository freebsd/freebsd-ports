--- aclocal.m4.orig	2006-12-27 04:28:00 UTC
+++ aclocal.m4
@@ -926,7 +926,7 @@ fi
 # restrict ourselves to GNU make (using the --version option ensures
 # this.)
 AC_DEFUN([AM_PROG_MKDIR_P],
-[if mkdir -p --version . >/dev/null 2>&1 && test ! -d ./--version; then
+[if mkdir -p . >/dev/null 2>&1 && test ! -d ./--version; then
   # Keeping the `.' argument allows $(mkdir_p) to be used without
   # argument.  Indeed, we sometimes output rules like
   #   $(mkdir_p) $(somedir)
