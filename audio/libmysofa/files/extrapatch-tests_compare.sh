Undo bashism added upstream in a5a3562. The built-in 'command' command of
sh(1) does not take multiple arguments.

--- tests/compare.sh.orig	2024-10-19 19:02:44 UTC
+++ tests/compare.sh
@@ -1,7 +1,7 @@ SCRIPTDIR=${0%/*}
 #!/bin/sh
 
 SCRIPTDIR=${0%/*}
-NODEJS=$(command -v node nodejs false | head -1)
+NODEJS=$(which node nodejs false | head -1)
 TMP1=`mktemp -p . tmp1-XXXXXXXX.json`
 TMP2=`mktemp -p . tmp2-XXXXXXXX.txt`
 TMP3=`mktemp -p . tmp3-XXXXXXXX.json`
