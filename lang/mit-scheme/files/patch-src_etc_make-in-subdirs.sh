--- etc/make-in-subdirs.sh.orig	2011-05-02 01:50:30.000000000 +0000
+++ etc/make-in-subdirs.sh
@@ -29,5 +29,5 @@ set -e
 TARGET=${1}
 shift
 for SUBDIR in "${@}"; do
-    run_cmd_in_dir "${SUBDIR}" make "${TARGET}"
+    run_cmd_in_dir "${SUBDIR}" gmake "${TARGET}"
 done
