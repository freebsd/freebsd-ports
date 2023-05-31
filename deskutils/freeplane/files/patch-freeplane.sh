--- freeplane.sh.orig	2023-05-28 13:36:42 UTC
+++ freeplane.sh
@@ -1,5 +1,9 @@
 #!/bin/bash
 
+if [ -z "$OSTYPE" ]; then
+	OSTYPE="$(uname -o)"
+fi
+
 # we only want to test the script, not Freeplane itself
 if ( echo "${DEBUG}" | grep -qe "script" ); then
 	set -x
@@ -146,7 +150,7 @@ if [ -x $(which readlink) ] && [ "`echo $OSTYPE | cut 
 	# if we have 'readlink' we can use it to get an absolute path
 	# -m should be faster and link does always resolve, else this script
 	# wouldn't be called, would it?
-	freefile=$(readlink -mn "$0")
+	freefile=$(readlink -fn "$0")
 	_debug "Link '$0' resolved to '${freefile}'."
 else
 	freefile="$0"
