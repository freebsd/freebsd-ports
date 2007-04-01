--- ros/src/WOKTclLib/wutils.tcl.orig	Fri Sep 21 10:08:43 2001
+++ ros/src/WOKTclLib/wutils.tcl	Thu Aug 10 17:20:24 2006
@@ -1770,7 +1770,7 @@
 	    }
 	    
 	    command {
-		set fid [open "| /usr/lib/sendmail -oi -t" "w"]
+		set fid [open "| /usr/sbin/sendmail -oi -t" "w"]
 		puts $fid "To: $to"
 		if {[string length $from] > 0} {
 		    puts $fid "From: $from"
