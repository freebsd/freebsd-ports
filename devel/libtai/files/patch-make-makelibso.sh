--- make-makelibso.sh.orig	Wed Dec 31 21:00:00 1969 UTC
+++ make-makelibso.sh
@@ -0,0 +1,3 @@
+echo 'main="$1"; shift'
+echo 'rm -f "$main"'
+echo $CC '-shared -Wl,-soname,$main -o "$main" ${1+"$@"}'
