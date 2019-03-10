--- ng/drawing.tcl.orig	2019-03-10 18:49:31 UTC
+++ ng/drawing.tcl
@@ -11,7 +11,7 @@ set oldmousey 0
 # use this one for Togl 2.0
 # if {[catch {togl .ndraw -width 400 -height 300  -rgba true -double true -depth true -privatecmap false -stereo false -indirect true -create init  -display draw -reshape reshape  }] } {    
 
-if {[catch {togl .ndraw -width 400 -height 300  -rgba true -double true -depth true -privatecmap false -stereo false -indirect true }] } {    puts "no OpenGL" 
+if {[catch {togl .ndraw -width 400 -height 300  -rgba true -double true -depth true -privatecmap false -stereo false -indirect false }] } {    puts "no OpenGL" 
 } {
     #
     pack .ndraw -expand true -fill both -padx 10 -pady 10
