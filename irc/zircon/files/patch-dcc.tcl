--- plugins/Dcc/dcc.tcl.orig	Tue Jul 10 17:40:00 2001
+++ plugins/Dcc/dcc.tcl	Wed Mar  3 04:24:11 2004
@@ -46,6 +46,15 @@
 		return 0
 	    }
 	    switch $posn [set fp [file size $file]] {} default {
+		foreach x [$net autoget] {
+			if {[regexp -- $x $usr]} {
+		      $net CTCP DCC [$usr name] "RESUME [deSpace [file tail $file]] $port $fp"
+		      global Resume
+		      if {![info exists Resume($usr)]} {$usr ref}
+		      lappend Resume($usr) [list $file $addr $port $leng $fp]
+		      return 0
+			}
+		}
 	        switch [tk_dialog .@dg$net {DCC Get} \
 	          "File \"$file\" already exists. Select the action you want to take." \
 	          warning 0 Overwrite Resume {Rename incoming} \
