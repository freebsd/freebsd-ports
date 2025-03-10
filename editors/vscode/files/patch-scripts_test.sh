--- scripts/test.sh.orig	2024-09-27 21:08:28 UTC
+++ scripts/test.sh
@@ -27,7 +27,7 @@ test -d node_modules || npm i
 test -d node_modules || npm i
 
 # Get electron
-npm run electron
+# npm run electron
 
 # Unit Tests
 if [[ "$OSTYPE" == "darwin"* ]]; then
