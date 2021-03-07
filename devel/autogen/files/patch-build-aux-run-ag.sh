--- build-aux/run-ag.sh.orig	2018-08-14 23:53:31 UTC
+++ build-aux/run-ag.sh
@@ -45,7 +45,7 @@ find_exe() {
   return 0
 }
 
-STAMP_TEMP_DIR=$(mktemp --suffix=.tdir -d /tmp/run-ag-XXXXXXXX)
+STAMP_TEMP_DIR=$(gmktemp --suffix=.tdir -d /tmp/run-ag-XXXXXXXX)
 exec 9>&2 2>> ${STAMP_TEMP_DIR}/mk-stamps.log
 VERBOSE=1
 
