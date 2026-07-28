Undo bashism added upstream in a5a3562. The built-in 'command' command of
sh(1) does not take multiple arguments.

--- tests/compareIgnoreNew.sh.orig	2026-07-19 09:52:37 UTC
+++ tests/compareIgnoreNew.sh
@@ -25,7 +25,7 @@ SCRIPTDIR=${0%/*}
 test -x "${mysofa2json}" || usage "No mysofa2json executable: '${mysofa2json}'"
 
 SCRIPTDIR=${0%/*}
-NODEJS=$(command -v node nodejs false | head -1)
+NODEJS=$(which node nodejs false | head -1)
 TMP1="$(mktemp -p . tmp1-XXXXXXXX.json)"
 TMP2="$(mktemp -p . tmp2-XXXXXXXX.txt)"
 TMP3="$(mktemp -p . tmp3-XXXXXXXX.json)"
