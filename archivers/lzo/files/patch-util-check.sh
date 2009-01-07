--- ./util/check.sh~	2009-01-04 10:28:23.000000000 +0100
+++ ./util/check.sh	2009-01-04 10:33:34.000000000 +0100
@@ -13,7 +13,7 @@
 LTEST="ltest"
 test -x ./ltest/ltest && LTEST="./ltest/ltest"
 test -x ./ltest.exe && LTEST="./ltest.exe"
-LFLAGS="-q -n2"
+LFLAGS="-Q -n2"
 
 dir="${*-.}"
 
