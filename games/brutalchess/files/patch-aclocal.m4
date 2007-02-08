--- aclocal.m4.orig	Tue Feb  6 23:28:00 2007
+++ aclocal.m4	Tue Feb  6 23:28:12 2007
@@ -926,7 +926,7 @@
 # restrict ourselves to GNU make (using the --version option ensures
 # this.)
 AC_DEFUN([AM_PROG_MKDIR_P],
-[if mkdir -p --version . >/dev/null 2>&1 && test ! -d ./--version; then
+[if mkdir -p . >/dev/null 2>&1 && test ! -d ./--version; then
   # Keeping the `.' argument allows $(mkdir_p) to be used without
   # argument.  Indeed, we sometimes output rules like
   #   $(mkdir_p) $(somedir)
