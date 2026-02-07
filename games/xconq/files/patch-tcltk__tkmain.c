--- tcltk/tkmain.c.orig	2013-05-14 12:13:15.000000000 +0200
+++ tcltk/tkmain.c	2013-05-14 12:13:42.000000000 +0200
@@ -313,11 +313,11 @@
     interp = Tcl_CreateInterp();
 
     if (Tcl_Init(interp) == TCL_ERROR) {
-	init_error("tcl init failed (%s), exiting", interp->result);
+	init_error("tcl init failed (%s), exiting", Tcl_GetStringResult(interp));
     }
 
     if (Tk_Init(interp) == TCL_ERROR) {
-	init_error("tk init failed (%s), exiting", interp->result);
+	init_error("tk init failed (%s), exiting", Tcl_GetStringResult(interp));
     }
 
     tcl_cmd("version_string", tk_version_string);
@@ -467,7 +467,7 @@
 		rslt = Tcl_EvalFile(interp, pathbuf);
 		if (rslt == TCL_ERROR)
 		  init_error("Error reading tcl from %s: %s",
-			     pathbuf, interp->result);
+			     pathbuf, Tcl_GetStringResult(interp));
 		loaded = TRUE;
 		break;
 	    }
@@ -482,7 +482,7 @@
 			rslt = Tcl_EvalFile(interp, pathbuf);
 			if (rslt == TCL_ERROR)
 			  init_error("Error reading tcl from %s: %s",
-				     pathbuf, interp->result);
+				     pathbuf, Tcl_GetStringResult(interp));
 			loaded = TRUE;
 			break;
 		    }
@@ -571,28 +571,28 @@
 tk_numgames(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
     collect_possible_games();
-    sprintf(interp->result, "%d", numgames);
+    sprintf(Tcl_GetStringResult(interp), "%d", numgames);
     return TCL_OK;
 }
 
 int
 tk_any_variants(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", any_variants);
+    sprintf(Tcl_GetStringResult(interp), "%d", any_variants);
     return TCL_OK;
 }
 
 int
 tk_listallgames(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", listallgames);
+    sprintf(Tcl_GetStringResult(interp), "%d", listallgames);
     return TCL_OK;
 }
 
 int
 tk_side_lib_size(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", length(g_side_lib()));
+    sprintf(Tcl_GetStringResult(interp), "%d", length(g_side_lib()));
     return TCL_OK;
 }
 
@@ -638,7 +638,7 @@
 	    break;
 	}
     }
-    sprintf(interp->result, "%d", rslt);
+    sprintf(Tcl_GetStringResult(interp), "%d", rslt);
     return TCL_OK;
 }
 
@@ -675,63 +675,63 @@
 int
 tk_numttypes(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", numttypes);
+    sprintf(Tcl_GetStringResult(interp), "%d", numttypes);
     return TCL_OK;
 }
 
 int
 tk_numutypes(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", numutypes);
+    sprintf(Tcl_GetStringResult(interp), "%d", numutypes);
     return TCL_OK;
 }
 
 int
 tk_nummtypes(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", nummtypes);
+    sprintf(Tcl_GetStringResult(interp), "%d", nummtypes);
     return TCL_OK;
 }
 
 int
 tk_numatypes(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", numatypes);
+    sprintf(Tcl_GetStringResult(interp), "%d", numatypes);
     return TCL_OK;
 }
 
 int
 tk_numsides(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", numsides);
+    sprintf(Tcl_GetStringResult(interp), "%d", numsides);
     return TCL_OK;
 }
 
 int
 tk_maxsides(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", g_sides_max());
+    sprintf(Tcl_GetStringResult(interp), "%d", g_sides_max());
     return TCL_OK;
 }
 
 int
 tk_minsides(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", g_sides_min());
+    sprintf(Tcl_GetStringResult(interp), "%d", g_sides_min());
     return TCL_OK;
 }
 
 int
 tk_numfeatures(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", numfeatures);
+    sprintf(Tcl_GetStringResult(interp), "%d", numfeatures);
     return TCL_OK;
 }
 
 int
 tk_numscorekeepers(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", numscorekeepers);
+    sprintf(Tcl_GetStringResult(interp), "%d", numscorekeepers);
     return TCL_OK;
 }
 
@@ -744,7 +744,7 @@
 	if (m_treasury(m))
 	  ++rslt;
     }
-    sprintf(interp->result, "%d", rslt);
+    sprintf(Tcl_GetStringResult(interp), "%d", rslt);
     return TCL_OK;
 }
 
@@ -760,7 +760,7 @@
 		break;
 	}
     }
-    sprintf(interp->result, "%d", n);
+    sprintf(Tcl_GetStringResult(interp), "%d", n);
     return TCL_OK;
 }
 
@@ -957,7 +957,7 @@
 
     s = strtol(argv[1], NULL, 10);
     if (between(0, s, numsides))
-      sprintf(interp->result, "%d", side_n(s)->ingame);
+      sprintf(Tcl_GetStringResult(interp), "%d", side_n(s)->ingame);
     else
       Tcl_SetResult(interp, "?s?", TCL_VOLATILE);
     return TCL_OK;
@@ -999,7 +999,7 @@
 
     p = strtol(argv[1], NULL, 10);
     player = find_player(p);
-    sprintf(interp->result, "%d", (player ? player->advantage : 0));
+    sprintf(Tcl_GetStringResult(interp), "%d", (player ? player->advantage : 0));
     return TCL_OK;
 }
 
@@ -1041,7 +1041,7 @@
 
     s = strtol(argv[1], NULL, 10);
     side = side_n(s);
-    sprintf(interp->result, "%d", (side ? side->minadvantage : 0));
+    sprintf(Tcl_GetStringResult(interp), "%d", (side ? side->minadvantage : 0));
     return TCL_OK;
 }
 
@@ -1053,7 +1053,7 @@
 
     s = strtol(argv[1], NULL, 10);
     side = side_n(s);
-    sprintf(interp->result, "%d", (side ? side->maxadvantage : 0));
+    sprintf(Tcl_GetStringResult(interp), "%d", (side ? side->maxadvantage : 0));
     return TCL_OK;
 }
 
@@ -1066,7 +1066,7 @@
     i = strtol(argv[1], NULL, 10);
     if (between(0, i, numsides)) {
 	side = assignments[i].side;
-	sprintf(interp->result, "%d", side->id);
+	sprintf(Tcl_GetStringResult(interp), "%d", side->id);
     } else {
         Tcl_SetResult(interp, "?s?", TCL_VOLATILE);
     }
@@ -1083,7 +1083,7 @@
     i = strtol(argv[1], NULL, 10);
     if (between(0, i, numsides)) {
 	player = assignments[i].player;
-	sprintf(interp->result, "%d", (player ? player->id : 0));
+	sprintf(Tcl_GetStringResult(interp), "%d", (player ? player->id : 0));
     } else {
         Tcl_SetResult(interp, "?s?", TCL_VOLATILE);
     }
@@ -1098,7 +1098,7 @@
 
     s = strtol(argv[1], NULL, 10);
     side = side_n(s);
-    sprintf(interp->result, "%d", side != NULL && !side->nameslocked);
+    sprintf(Tcl_GetStringResult(interp), "%d", side != NULL && !side->nameslocked);
     return TCL_OK;
 }
 
@@ -1124,7 +1124,7 @@
 
     n = net_add_side_and_player();
     /* Return the position of the new side/player in the assignment array. */
-    sprintf(interp->result, "%d", n);
+    sprintf(Tcl_GetStringResult(interp), "%d", n);
     return TCL_OK;
 }
 
@@ -1137,7 +1137,7 @@
     s = strtol(argv[1], NULL, 10);
     rslt = net_remove_side_and_player(s);
     /* Return TRUE or FALSE depending on the outcome. */
-    sprintf(interp->result, "%d", rslt);
+    sprintf(Tcl_GetStringResult(interp), "%d", rslt);
     return TCL_OK;
 }
 
@@ -1182,7 +1182,7 @@
     n2 = strtol(argv[2], NULL, 10);
     if (between(0, n, numsides)) {
 	n2 = net_exchange_players(n, n2);
-	sprintf(interp->result, "%d", n2);
+	sprintf(Tcl_GetStringResult(interp), "%d", n2);
     } else {
         Tcl_SetResult(interp, "?s?", TCL_VOLATILE);
     }
@@ -1209,7 +1209,7 @@
 int
 tk_dside(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", dside->id);
+    sprintf(Tcl_GetStringResult(interp), "%d", dside->id);
     return TCL_OK;
 }
 
@@ -1222,9 +1222,9 @@
     fid = strtol(argv[1], NULL, 10);
     feature = find_feature(fid);
     if (feature == NULL)
-      sprintf(interp->result, "{\"%s\" \"%s\"}", "no %t", "feature");
+      sprintf(Tcl_GetStringResult(interp), "{\"%s\" \"%s\"}", "no %t", "feature");
     else if (feature->name != NULL || feature->feattype != NULL)
-      sprintf(interp->result, "{\"%s\" \"%s\"}",
+      sprintf(Tcl_GetStringResult(interp), "{\"%s\" \"%s\"}",
 	      (feature->name ? feature->name : ""),
 	      (feature->feattype ? feature->feattype : ""));
     else
@@ -1341,7 +1341,7 @@
     sprintf (bigbuf, "set game_blurb(%d) \"%s\"", gamei, blurb);
     rslt = Tcl_GlobalEval(interp, bigbuf);
     if (rslt == TCL_ERROR) {
-	fprintf(stderr, "Error: %s\n", interp->result);
+	fprintf(stderr, "Error: %s\n", Tcl_GetStringResult(interp));
 	fprintf(stderr, "Error: while processing the %s blurb.\n", name);
     }
     return TCL_OK;
@@ -1428,7 +1428,7 @@
     int rslt;
 
     rslt = try_join_game(argv[1]);
-    sprintf(interp->result, "%d", rslt);
+    sprintf(Tcl_GetStringResult(interp), "%d", rslt);
     return TCL_OK;
 }
 
@@ -1512,7 +1512,7 @@
 #else
       interval = 50;
 #endif
-    sprintf(interp->result, "%d", interval);
+    sprintf(Tcl_GetStringResult(interp), "%d", interval);
     return TCL_OK;
 }
 
@@ -3265,7 +3265,7 @@
     rslt = Tcl_Eval(interp, tclbuf);
 #endif
     if (rslt == TCL_ERROR) {
-	fprintf(stderr, "Error: %s\n", interp->result);
+	fprintf(stderr, "Error: %s\n", Tcl_GetStringResult(interp));
 	fprintf(stderr, "Error: while updating help node %s\n",
 		cur_help_node->key);
     }
@@ -3368,7 +3368,7 @@
 	}
 	map->prefixarg += (map->inpch - '0');
 	/* Return the prefix arg so we can display it. */
-	sprintf(interp->result, "%d", map->prefixarg);
+	sprintf(Tcl_GetStringResult(interp), "%d", map->prefixarg);
 	return TCL_OK;
     } else {
 	/* In any other situation, the character is a single-letter
@@ -3386,7 +3386,7 @@
     if (map->modalhandler == NULL)
       map->prefixarg = -1;
     /* Return the prefix arg so we can display it. */
-    sprintf(interp->result, "%d", map->prefixarg);
+    sprintf(Tcl_GetStringResult(interp), "%d", map->prefixarg);
     return TCL_OK;
 }
 
@@ -3610,7 +3610,7 @@
     for_all_maps(map) {
 	set_tool_cursor(map, 0);
     }
-    sprintf(interp->result, "%d", val);
+    sprintf(Tcl_GetStringResult(interp), "%d", val);
     return TCL_OK;
 }
 
@@ -3629,7 +3629,7 @@
     dside->ui->legends = NULL;
     /* (this won't work if networking is on, feature might not
        exist yet) */
-    sprintf(interp->result, "%d", (feature ? feature->id : 0));
+    sprintf(Tcl_GetStringResult(interp), "%d", (feature ? feature->id : 0));
     return TCL_OK;
 }
 
@@ -3741,7 +3741,7 @@
 	if (utype_indexes[u] >=0)
 	  ++num;
     }
-    sprintf(interp->result, "%d", num);
+    sprintf(Tcl_GetStringResult(interp), "%d", num);
     return TCL_OK;
 }
 
@@ -3753,12 +3753,12 @@
     n = strtol(argv[1], NULL, 10);
     for_all_unit_types(u) {
 	if (utype_indexes[u] == n) {
-	    sprintf(interp->result, "%d", u);
+	    sprintf(Tcl_GetStringResult(interp), "%d", u);
 	    return TCL_OK;
 	}
     }
     /* (should make error) */
-    sprintf(interp->result, "%d", -1);
+    sprintf(Tcl_GetStringResult(interp), "%d", -1);
     return TCL_OK;
 }
 
@@ -3770,12 +3770,12 @@
     n = strtol(argv[1], NULL, 10);
     for_all_material_types(m) {
 	if (mtype_indexes[m] == n) {
-	    sprintf(interp->result, "%d", m);
+	    sprintf(Tcl_GetStringResult(interp), "%d", m);
 	    return TCL_OK;
 	}
     }
     /* (should make error) */
-    sprintf(interp->result, "%d", -1);
+    sprintf(Tcl_GetStringResult(interp), "%d", -1);
     return TCL_OK;
 }
 
@@ -3785,7 +3785,7 @@
     int viewpow;
 
     viewpow = strtol(argv[1], NULL, 10);
-    sprintf(interp->result, "%d %d", area.width * hws[viewpow], 0);
+    sprintf(Tcl_GetStringResult(interp), "%d %d", area.width * hws[viewpow], 0);
     return TCL_OK;
 }
 
@@ -3810,7 +3810,7 @@
     if (n == 1 && in_play(unit)) {
 	recenter(map, unit->x, unit->y);
     }
-    sprintf(interp->result, "%d", n);
+    sprintf(Tcl_GetStringResult(interp), "%d", n);
     return TCL_OK;
 }
 
@@ -3847,11 +3847,11 @@
     if (numatypes > 0 
         && is_advance_type(this_advance)
         && is_advance_type(needed_advance)) {        
-          sprintf(interp->result, "%d", aa_needed_to_research(this_advance, needed_advance));
+          sprintf(Tcl_GetStringResult(interp), "%d", aa_needed_to_research(this_advance, needed_advance));
 	return TCL_OK;
     } else {
 	/* (should make error) */
-	sprintf(interp->result, "%d", -1);
+	sprintf(Tcl_GetStringResult(interp), "%d", -1);
 	return TCL_OK;
     }
 }
@@ -3985,7 +3985,7 @@
     strcpy(backup, tclbuf);
     rslt = Tcl_GlobalEval(interp, tclbuf);
     if (rslt == TCL_ERROR) {
-	fprintf(stderr, "Error: %s\n", interp->result);
+	fprintf(stderr, "Error: %s\n", Tcl_GetStringResult(interp));
 	fprintf(stderr, "Error: while evaluating `%s'\n", backup);
     }
 }
