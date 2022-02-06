--- scripts/test.sh.orig	2022-02-05 06:42:53 UTC
+++ scripts/test.sh
@@ -27,7 +27,7 @@ VSCODECRASHDIR=$ROOT/.build/crashes
 test -d node_modules || yarn
 
 # Get electron
-yarn electron
+# yarn electron
 
 # Unit Tests
 if [[ "$OSTYPE" == "darwin"* ]]; then
