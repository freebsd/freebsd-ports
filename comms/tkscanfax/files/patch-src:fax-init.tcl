--- fax-init.tcl.orig	Wed Nov 17 20:07:15 2004
+++ fax-init.tcl	Wed Nov 17 20:07:34 2004
@@ -409,6 +409,7 @@
     set fid [open $lockfile r]
     gets $fid pid
     close $fid
+    set notrun 1
     catch {set notrun [exec sh -c "ps -p $pid > /dev/null; echo $?"]}
     if {! $notrun} {
         if  [tk_dialog .dialog "TkFax lock file found" \
