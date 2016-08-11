--- rexxtest.rexx.orig	1999-01-22 00:11:44 UTC
+++ rexxtest.rexx
@@ -1,4 +1,4 @@
-/* test program for interpreter */
+/*usr/bin/true;exec rexx -x "$0" "$@";exit# test program for interpreter */
 
 signal on syntax
 parse source sys how me nick env
