Undo bashism added upstream in a5a3562. The built-in 'command' command of
sh(1) does not take multiple arguments.
--- tests/compare.sh.orig	2022-02-14 10:05:41 UTC
+++ tests/compare.sh
@@ -1,7 +1,7 @@
 #!/bin/sh
 
 SCRIPTDIR=${0%/*}
-NODEJS=$(command -v node nodejs false | head -1)
+NODEJS=$(which node nodejs false | head -1)
 
 ${MYSOFA2JSON:-${SCRIPTDIR}/../build/src/mysofa2json} -c -s "$1".sofa >tmp1.json 2>tmp1.txt
 
