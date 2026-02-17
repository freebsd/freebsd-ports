--- scripts/dw-start.sh.orig	2026-02-17 05:41:09 UTC
+++ scripts/dw-start.sh
@@ -68,8 +68,7 @@ DWCMD="$DIREWOLF -a 100"
 
 
 #Where will logs go - needs to be writable by non-root users
-LOGFILE=/var/tmp/dw-start.log
-
+LOGFILE=/var/log/dw-start.log
 
 #-------------------------------------
 # Main functions of the script
