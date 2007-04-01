--- wok/lib/wutils.tcl.orig	Fri Sep 21 10:08:43 2001
+++ wok/lib/wutils.tcl	Thu Aug 10 17:17:32 2006
@@ -1770,7 +1770,7 @@
 	    }
 	    
 	    command {
-		set fid [open "| /usr/lib/sendmail -oi -t" "w"]
+		set fid [open "| /usr/sbin/sendmail -oi -t" "w"]
 		puts $fid "To: $to"
 		if {[string length $from] > 0} {
 		    puts $fid "From: $from"
