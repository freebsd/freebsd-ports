--- agen5/mk-stamps.sh.orig	2018-08-04 20:22:34 UTC
+++ agen5/mk-stamps.sh
@@ -28,7 +28,7 @@
 #  because some of the rules are complex and we don't want to
 #  deal with the dual update problem.
 
-STAMP_TEMP_DIR=$(mktemp --suffix=.tdir -d /tmp/mk-stamps-XXXXXXXX)
+STAMP_TEMP_DIR=$(gmktemp --suffix=.tdir -d /tmp/mk-stamps-XXXXXXXX)
 exec 9>&2 2>> ${STAMP_TEMP_DIR}/mk-stamps.log
 stop_tracing=:
 if (shopt -qo xtrace)
