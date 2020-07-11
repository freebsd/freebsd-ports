--- scripts/wsrep_sst_rsync.sh.orig	2020-05-09 19:28:00 UTC
+++ scripts/wsrep_sst_rsync.sh
@@ -390,7 +390,14 @@ EOF
 
 elif [ "$WSREP_SST_OPT_ROLE" = "joiner" ]
 then
-    wsrep_check_programs lsof
+    case $OS in
+    FreeBSD)
+        wsrep_check_programs sockstat
+        ;;
+    *)
+        wsrep_check_programs lsof
+        ;;
+    esac
 
     touch $SST_PROGRESS_FILE
     MYSQLD_PID=$WSREP_SST_OPT_PARENT
