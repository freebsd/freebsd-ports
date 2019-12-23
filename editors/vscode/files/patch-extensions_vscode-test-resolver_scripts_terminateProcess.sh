--- extensions/vscode-test-resolver/scripts/terminateProcess.sh.orig	2019-12-18 06:39:18 UTC
+++ extensions/vscode-test-resolver/scripts/terminateProcess.sh
@@ -1,7 +1,7 @@
 #!/bin/bash
 
 terminateTree() {
-	for cpid in $(/usr/bin/pgrep -P $1); do
+	for cpid in $(/bin/pgrep -P $1); do
 		terminateTree $cpid
 	done
 	kill -9 $1 > /dev/null 2>&1
@@ -9,4 +9,4 @@ terminateTree() {
 
 for pid in $*; do
 	terminateTree $pid
-done
\ No newline at end of file
+done
