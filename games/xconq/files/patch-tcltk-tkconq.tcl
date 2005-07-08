diff -Naur tcltk.orig/tkconq.tcl tcltk/tkconq.tcl
--- tcltk.orig/tkconq.tcl	Thu Jul  7 14:35:10 2005
+++ tcltk/tkconq.tcl	Thu Jul  7 14:35:47 2005
@@ -472,7 +472,7 @@
 		    -state $variantstate($col2) -variable variantvalue($col2) \
 		    -command [ list set_variant_value_cmd $col2 ]
 	    grid .newgame.top.checks.v$col1 .newgame.top.checks.v$col2 \
-		    -sticky w -pad 5
+		    -sticky w -padx 5 -pady 5
 	}
 	for { set v 0 } { $v < 16 } { incr v } {
 	    if { "$variantstate($v)" == "active" } {
@@ -785,37 +785,37 @@
 	    -command { adjust_advantage_cmd 1 }
     button .newgame.top.plbuttons.aminus -text "A-" -state disabled \
 	    -command { adjust_advantage_cmd -1 }
-    grid .newgame.top.plbuttons.aplus .newgame.top.plbuttons.aminus -sticky ew -pad 2
+    grid .newgame.top.plbuttons.aplus .newgame.top.plbuttons.aminus -sticky ew -padx 2 -pady 2
     button .newgame.top.plbuttons.add -text "Add" \
 	    -command { add_player_cmd } -width 8
-    grid .newgame.top.plbuttons.add -columnspan 2 -sticky ew -pad 2
+    grid .newgame.top.plbuttons.add -columnspan 2 -sticky ew -padx 2 -pady 2
     button .newgame.top.plbuttons.remove -text "Remove" -width 8
-    grid .newgame.top.plbuttons.remove -columnspan 2 -sticky ew -pad 2
+    grid .newgame.top.plbuttons.remove -columnspan 2 -sticky ew -padx 2 -pady 2
 
     menubutton .newgame.top.plbuttons.sidelib -text "Side Name" \
 	    -menu .newgame.top.plbuttons.sidelib.menu \
 	    -borderwidth 2 -relief raised -width 8
     menu .newgame.top.plbuttons.sidelib.menu -tearoff 0
-    grid .newgame.top.plbuttons.sidelib -columnspan 2 -sticky ew -pad 2
+    grid .newgame.top.plbuttons.sidelib -columnspan 2 -sticky ew -padx 2 -pady 2
 
     button .newgame.top.plbuttons.rename -text "Random" \
 	    -command { rename_side_for_player_cmd -1 } -width 8
-    grid .newgame.top.plbuttons.rename -columnspan 2 -sticky ew -pad 2
+    grid .newgame.top.plbuttons.rename -columnspan 2 -sticky ew -padx 2 -pady 2
     button .newgame.top.plbuttons.computer -text "Computer" \
 	    -command { cycle_ai_cmd } -width 8
-    grid .newgame.top.plbuttons.computer -columnspan 2 -sticky ew -pad 2
+    grid .newgame.top.plbuttons.computer -columnspan 2 -sticky ew -padx 2 -pady 2
     button .newgame.top.plbuttons.exchange -text "Exchange" \
 	    -command { exchange_players_cmd } -width 8
-    grid .newgame.top.plbuttons.exchange -columnspan 2 -sticky ew -pad 2
+    grid .newgame.top.plbuttons.exchange -columnspan 2 -sticky ew -padx 2 -pady 2
 
     label .newgame.top.plbuttons.indeplabel -text "Indep Units"
-    grid .newgame.top.plbuttons.indeplabel -columnspan 2 -sticky ew -pad 2
+    grid .newgame.top.plbuttons.indeplabel -columnspan 2 -sticky ew -padx 2 -pady 2
     button .newgame.top.plbuttons.indepside -text "Add AI" \
 	    -command { set_indepside toggle } -width 6
-    grid .newgame.top.plbuttons.indepside -columnspan 2 -pad 2
+    grid .newgame.top.plbuttons.indepside -columnspan 2 -padx 2 -pady 2
     button .newgame.top.plbuttons.indepconfig -text "Config" \
 	    -command { popup_indepside_config } -width 6
-    grid .newgame.top.plbuttons.indepconfig -columnspan 2 -pad 2
+    grid .newgame.top.plbuttons.indepconfig -columnspan 2 -padx 2 -pady 2
 
     # Add names to the side library menu, disabling already-used names.
     set numsidelib [ side_lib_size ]
