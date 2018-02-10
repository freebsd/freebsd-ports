Fix binary location.

--- tests/compare.sh.orig	2018-02-08 14:33:00 UTC
+++ tests/compare.sh
@@ -1,7 +1,7 @@
 #!/bin/bash 
 
 NODEJS=`which node || which nodejs || which false`
-../build/src/mysofa2json "$1".sofa >tmp1.json 2>tmp1.txt 
+../src/mysofa2json "$1".sofa >tmp1.json 2>tmp1.txt 
 
 ret=$?
 if [ "$ret" != 0 ]; then 
