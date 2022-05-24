--- scripts/wsrep_sst_mariabackup.sh.orig	2022-05-24 14:46:36 UTC
+++ scripts/wsrep_sst_mariabackup.sh
@@ -725,7 +725,7 @@ recv_joiner()
     local ltcmd="$tcmd"
     if [ $tmt -gt 0 ]; then
         if [ -n "$(commandex timeout)" ]; then
-            if timeout --help | grep -qw -F -- '-k'; then
+            if timeout --help 2>&1 | grep -qw -F -- '-k'; then
                 ltcmd="timeout -k $(( tmt+10 )) $tmt $tcmd"
             else
                 ltcmd="timeout -s9 $tmt $tcmd"
