--- scripts/wsrep_sst_mariabackup.sh.orig	2022-02-14 08:10:09 UTC
+++ scripts/wsrep_sst_mariabackup.sh
@@ -715,7 +715,7 @@ recv_joiner()
     local ltcmd="$tcmd"
     if [ $tmt -gt 0 ]; then
         if [ -n "$(commandex timeout)" ]; then
-            if timeout --help | grep -qw -- '-k'; then
+            if timeout --help 2>&1 | grep -qw -- '-k'; then
                 ltcmd="timeout -k $(( tmt+10 )) $tmt $tcmd"
             else
                 ltcmd="timeout -s9 $tmt $tcmd"
