--- rexxtest.rexx	Thu Jan 21 16:11:44 1999
+++ rexxtest.rexx.new	Fri Sep  7 15:04:39 2001
@@ -1,4 +1,4 @@
-/* test program for interpreter */
+/*usr/bin/true;exec rexx -x "$0" "$@";exit# test program for interpreter */
 
 signal on syntax
 parse source sys how me nick env
