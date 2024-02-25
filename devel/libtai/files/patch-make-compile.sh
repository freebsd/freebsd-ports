--- make-compile.sh.orig	Tue Oct 13 14:52:20 1998 UTC
+++ make-compile.sh
@@ -1 +1,2 @@
-echo exec "$CC" -c '${1+"$@"}'
+echo "$CC" -c '${1+"$@"}'
+echo "$CC" $CCSO -o '${1%.c}'.so -c '${1+"$@"}'
