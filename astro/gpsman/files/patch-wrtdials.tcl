diff -ruN gmsrc/wrtdials.tcl gmsrc/wrtdials.tcl
--- gmsrc/wrtdials.tcl	2008-10-28 10:19:48.000000000 -0700
+++ gmsrc/wrtdials.tcl	2008-11-10 04:39:44.000000000 -0800
@@ -17,7 +17,7 @@
 #      along with this program.
 #
 #  File: wrtdials.tcl
-#  Last change:  14 September 2008
+#  Last change:  8 November 2008
 #
 # Includes contributions by
 #  - Brian Baulch (baulchb _AT_ onthenet.com.au) marked "BSB contribution"
@@ -4099,8 +4099,8 @@
 				}
 				break
 			    }
+			    incr i
 			}
-			incr i
 		    }
 		}
 		if { $wh == "WP" } {
