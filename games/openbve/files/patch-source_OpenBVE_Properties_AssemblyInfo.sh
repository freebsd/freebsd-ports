--- source/OpenBVE/Properties/AssemblyInfo.sh.orig	2020-09-21 21:11:53 UTC
+++ source/OpenBVE/Properties/AssemblyInfo.sh
@@ -1,4 +1,4 @@
-#!/usr/bin/env bash
+#!/bin/sh
 #Set base development branch revision numbers
 #This needs to be bumped once we have a stable release branch
 MajorVersion=1
@@ -13,14 +13,14 @@ if (git describe --tags --exact-match 2> /dev/null) th
 	InfoVersion=$(git describe --tags)
 else
 	# determine revision and build numbers
-	if [[ "$OSTYPE" == "darwin"* ]]; then
+	if [ "${OSTYPE%%[0-9]*}" = "darwin" ]; then
 		#OSX
-		Revision=$(((($(date +%s) - $(date -jf "%Y-%m-%d" "2019-10-29" $B +%s))/86400 )+40 ))
-		Minutes=$(( $(date "+10#%H * 60 + 10#%M") ))
+		Revision=$(((($(gdate +%s) - $(gdate -jf "%Y-%m-%d" "2019-10-29" $B +%s))/86400 )+40 ))
+		Minutes=$(( $(gdate "+10#%H * 60 + 10#%M") ))
 	else
 		#Linux & Cygwin
-		Revision=$(( ( ($(date "+%s") - $(date --date="2019-10-29" +%s))/(60*60*24) )+40 ))
-		Minutes=$(( ( $(date "+%s") - $(date -d "today 0" +%s))/60 ))
+		Revision=$(( ( ($(gdate "+%s") - $(gdate --date="2019-10-29" +%s))/(60*60*24) )+40 ))
+		Minutes=$(( ( $(gdate "+%s") - $(gdate -d "today 0" +%s))/60 ))
 	fi
 
 	Version=$MajorVersion.$MinorVersion.$Revision.$Minutes
