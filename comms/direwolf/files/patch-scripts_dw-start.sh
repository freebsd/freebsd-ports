--- scripts/dw-start.sh.orig	2022-01-28 14:55:02 UTC
+++ scripts/dw-start.sh
@@ -68,9 +68,9 @@ DWCMD="$DIREWOLF -a 100"
 
 
 #Where will logs go - needs to be writable by non-root users
-LOGFILE=/var/tmp/dw-start.log
+#LOGFILE=/var/tmp/dw-start.log
+LOGFILE=/var/var/dw-start.log
 
-
 #-------------------------------------
 # Main functions of the script
 #-------------------------------------
@@ -157,7 +157,7 @@ function GUI {
 # When running from cron, we have a very minimal environment
 # including PATH=/usr/bin:/bin.
 #
-export PATH=/usr/local/bin:$PATH
+export PATH=%%PREFIX%%/bin:$PATH
 
 #Log the start of the script run and re-run
 date >> $LOGFILE
