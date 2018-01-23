--- freeplane.sh.orig	2018-01-07 18:16:56 UTC
+++ freeplane.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 # we only want to test the script, not Freeplane itself
 if ( echo "${DEBUG}" | grep -qe "script" ); then
@@ -123,7 +123,7 @@ if [ -x $(which readlink) ] && [ "`echo $OSTYPE | cut 
 	# if we have 'readlink' we can use it to get an absolute path
 	# -m should be faster and link does always resolve, else this script
 	# wouldn't be called, would it?
-	freefile=$(readlink -mn "$0")
+	freefile=$(readlink -n "$0")
 	_debug "Link '$0' resolved to '${freefile}'."
 else
 	freefile="$0"
