--- scripts/test.sh.orig	2025-05-12 00:03:54 UTC
+++ scripts/test.sh
@@ -24,7 +24,7 @@ test -d node_modules || npm i
 test -d node_modules || npm i
 
 # Get electron
-npm run electron
+# npm run electron
 
 # Unit Tests
 if [[ "$OSTYPE" == "darwin"* ]]; then
