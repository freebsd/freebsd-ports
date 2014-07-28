--- make-makelibso.sh.orig	Wed Dec 31 21:00:00 1969
+++ make-makelibso.sh	Fri Jun 16 19:32:24 2000
@@ -0,0 +1,3 @@
+echo 'main="$1"; shift'
+echo 'rm -f "$main"'
+echo $CC '-shared -Wl,-soname,$main -o "$main" ${1+"$@"}'
