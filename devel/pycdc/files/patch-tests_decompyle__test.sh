--- tests/decompyle_test.sh.orig	2024-08-10 12:46:23 UTC
+++ tests/decompyle_test.sh
@@ -6,7 +6,7 @@ if [[ -z "$PYTHON_EXE" ]]; then
 outdir="$2"
 
 if [[ -z "$PYTHON_EXE" ]]; then
-    PYTHON_EXE="$(which python3)"
+    PYTHON_EXE="%%PYTHON_CMD%%"
 fi
 
 if [[ -z "$testname" ]]; then
