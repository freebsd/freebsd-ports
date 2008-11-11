diff -ruN gmsrc/garmin.tcl gmsrc/garmin.tcl
--- gmsrc/garmin.tcl	2008-10-28 10:19:48.000000000 -0700
+++ gmsrc/garmin.tcl	2008-11-10 04:39:44.000000000 -0800
@@ -17,7 +17,7 @@
 #      along with this program.
 #
 #  File: garmin.tcl
-#  Last change:  23 October 2008
+#  Last change:  2 November 2008
 #
 # Includes contributions by
 # - David Gardner (djgardner_AT_users.sourceforge.net) marked
@@ -2567,7 +2567,7 @@
 }
 
 proc ConvGarminDate {gd} {
-    # converts Garmin date (seconds since 1990.01.01 00:00:00) into list
+    # converts Garmin date (seconds since 1989.12.31 00:00:00) into list
     #  with date in current format and seconds since beginning of $YEAR0,
     #  not necessarily a leap year, but < 1990
     global YEAR0 TimeOffset
@@ -2579,7 +2579,7 @@
 	if { $yy%100!=0 || $yy%400==0 } { incr dd }
 	incr yy 4
     }
-    set secs [expr round((((1990-$YEAR0)*365+$dd)*24+$TimeOffset-12)*3600+$gd)]
+    set secs [expr round((((1990-$YEAR0)*365+$dd)*24+$TimeOffset)*3600+$gd)]
     return [list [DateFromSecs $secs] $secs]
 }
 
