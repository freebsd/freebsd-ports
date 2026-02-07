--- docear.sh.orig	2015-10-26 17:10:56 UTC
+++ docear.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 # we only want to test the script, not Freeplane itself
 if ( echo "${DEBUG}" | grep -qe "script" )
@@ -137,7 +137,7 @@ if [ -x $(which readlink) ] && [ "`echo 
 then # if we have 'readlink' we can use it to get an absolute path
 	# -m should be faster and link does always resolve, else this script
 	# wouldn't be called, would it?
-	freefile=$(readlink -mn "$0")
+	freefile=$(readlink -n "$0")
 	_debug "Link '$0' resolved to '${freefile}'."
 else
 	freefile="$0"
@@ -190,6 +190,7 @@ then # non-Sun environments don't work c
 fi
 _debug "Calling: "\
 "${JAVACMD}" -Xmx512m\
+ "-Dawt.useSystemAAFontSettings=on"\
  "-Dorg.freeplane.param1=$1"\
  "-Dorg.freeplane.param2=$2"\
  "-Dorg.freeplane.param3=$3"\
@@ -204,6 +205,7 @@ _debug "Calling: "\
  -xargs "${freedir}/init.xargs"
 ( echo "${DEBUG}" | grep -qe "exit" ) && exit 0 # do not start Freeplane
 "${JAVACMD}" -Xmx512m\
+ "-Dawt.useSystemAAFontSettings=on"\
  "-Dorg.freeplane.param1=$1"\
  "-Dorg.freeplane.param2=$2"\
  "-Dorg.freeplane.param3=$3"\
