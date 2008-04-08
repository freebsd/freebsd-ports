--- ayam.c.orig	2007-09-21 13:30:36.000000000 +0200
+++ ayam.c	2007-12-17 19:12:10.000000000 +0100
@@ -842,8 +842,8 @@
   /* objsel.c */
   Togl_CreateCommand("processObjSel", ay_objsel_processcb);
 
-  Tcl_CreateCommand(interp, "getNameFromNode", ay_objsel_getnmfrmndtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getNameFromNode", (Tcl_CmdProc *)ay_objsel_getnmfrmndtcmd,
+		    NULL, NULL);
 
   /* pact.c */
   Togl_CreateCommand("selpac", ay_pact_seltcb);
@@ -864,25 +864,25 @@
 
   Togl_CreateCommand("wrpac", ay_pact_wrtcb);
 
-  Tcl_CreateCommand(interp, "centerPnts", ay_pact_centertcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "centerPnts", (Tcl_CmdProc *)ay_pact_centertcmd,
+		    NULL, NULL);
 
   Togl_CreateCommand("snapac", ay_pact_snaptogridcb);
 
 
   /* selp.c */
-  Tcl_CreateCommand(interp, "selPoints", ay_selp_selalltcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "selPoints", (Tcl_CmdProc *)ay_selp_selalltcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "applyTrafo", ay_selp_applytrafotcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "applyTrafo", (Tcl_CmdProc *)ay_selp_applytrafotcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "invSelPoints", ay_selp_inverttcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "invSelPoints", (Tcl_CmdProc *)ay_selp_inverttcmd,
+		    NULL, NULL);
 
   /* undo.c */
-  Tcl_CreateCommand(interp, "undo", ay_undo_undotcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "undo", (Tcl_CmdProc *)ay_undo_undotcmd,
+		    NULL, NULL);
 
   /* vact.c */
   Togl_CreateCommand("movevac", ay_vact_movetcb);
@@ -913,150 +913,150 @@
   /* w32t.c */
 #ifdef WIN32
   Tcl_CreateCommand(interp, "w32kill", ay_w32t_w32killtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+		    NULL, NULL);
 #endif
 
   /* wrib.c */
   Togl_CreateCommand("wrib", ay_wrib_cb);
 
-  Tcl_CreateCommand(interp, "wrib", ay_wrib_tcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "wrib", (Tcl_CmdProc *)ay_wrib_tcmd,
+		    NULL, NULL);
 
   /* write.c */
-  Tcl_CreateCommand(interp, "saveScene", ay_write_scenetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "saveScene", (Tcl_CmdProc *)ay_write_scenetcmd,
+		    NULL, NULL);
 
 
   /* contrib/tree.c */
   /*
   Tcl_CreateCommand(interp, "treeInit", ay_tree_inittcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+		    NULL, NULL);
   */
   /* NURBS */
 
   /* nurbs/nct.c */
-  Tcl_CreateCommand(interp, "refineNC", ay_nct_refinetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "refineNC", (Tcl_CmdProc *)ay_nct_refinetcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "coarsenNC", ay_nct_coarsentcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "coarsenNC", (Tcl_CmdProc *)ay_nct_coarsentcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "clampNC", ay_nct_clamptcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "clampNC", (Tcl_CmdProc *)ay_nct_clamptcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "elevateNC", ay_nct_elevatetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "elevateNC", (Tcl_CmdProc *)ay_nct_elevatetcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "insknNC", ay_nct_insertkntcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "insknNC", (Tcl_CmdProc *)ay_nct_insertkntcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "remknNC", ay_nct_removekntcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "remknNC", (Tcl_CmdProc *)ay_nct_removekntcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "collMP", ay_nct_collapsetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "collMP", (Tcl_CmdProc *)ay_nct_collapsetcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "explMP", ay_nct_explodetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "explMP", (Tcl_CmdProc *)ay_nct_explodetcmd,
+		    NULL, NULL);
 
   Togl_CreateCommand("finduac", ay_nct_finducb);
 
-  Tcl_CreateCommand(interp, "splitNC", ay_nct_splittcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "splitNC", (Tcl_CmdProc *)ay_nct_splittcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "concatNC", ay_nct_concattcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "concatNC", (Tcl_CmdProc *)ay_nct_concattcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "crtNCircle", ay_nct_crtncircletcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "crtNCircle", (Tcl_CmdProc *)ay_nct_crtncircletcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "crtNRect", ay_nct_crtrecttcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "crtNRect", (Tcl_CmdProc *)ay_nct_crtrecttcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "crtClosedBS", ay_nct_crtclosedbsptcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "crtClosedBS", (Tcl_CmdProc *)ay_nct_crtclosedbsptcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "rescaleKnNC", ay_nct_rescaleknvnctcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "rescaleKnNC", (Tcl_CmdProc *)ay_nct_rescaleknvnctcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "curvPlot", ay_nct_curvplottcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "curvPlot", (Tcl_CmdProc *)ay_nct_curvplottcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "shiftClosedBS", ay_nct_shiftcbstcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "shiftClosedBS", (Tcl_CmdProc *)ay_nct_shiftcbstcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "toXYNC", ay_nct_toxytcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "toXYNC", (Tcl_CmdProc *)ay_nct_toxytcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "makeCompNC", ay_nct_makecomptcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "makeCompNC", (Tcl_CmdProc *)ay_nct_makecomptcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "centerNC", ay_nct_centertcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "centerNC", (Tcl_CmdProc *)ay_nct_centertcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "trimNC", ay_nct_trimtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "trimNC", (Tcl_CmdProc *)ay_nct_trimtcmd,
+		    NULL, NULL);
 
   /* nurbs/npt.c */
-  Tcl_CreateCommand(interp, "crtNSphere", ay_npt_crtnspheretcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "crtNSphere", (Tcl_CmdProc *)ay_npt_crtnspheretcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "crtNSphere2", ay_npt_crtnsphere2tcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "crtNSphere2", (Tcl_CmdProc *)ay_npt_crtnsphere2tcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "splitNP", ay_npt_splittocurvestcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "splitNP", (Tcl_CmdProc *)ay_npt_splittocurvestcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "buildNP", ay_npt_buildfromcurvestcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "buildNP", (Tcl_CmdProc *)ay_npt_buildfromcurvestcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "topoly", ay_tess_npatchtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "topoly", (Tcl_CmdProc *)ay_tess_npatchtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "elevateNPU", ay_npt_elevateutcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "elevateNPU", (Tcl_CmdProc *)ay_npt_elevateutcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "elevateNPV", ay_npt_elevatevtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "elevateNPV", (Tcl_CmdProc *)ay_npt_elevatevtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "swapUV", ay_npt_swapuvtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "swapUV", (Tcl_CmdProc *)ay_npt_swapuvtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "revertU", ay_npt_revertutcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "revertU", (Tcl_CmdProc *)ay_npt_revertutcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "revertV", ay_npt_revertvtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "revertV", (Tcl_CmdProc *)ay_npt_revertvtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "closeNPU", ay_npt_closeutcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "closeNPU", (Tcl_CmdProc *)ay_npt_closeutcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "closeNPV", ay_npt_closevtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "closeNPV", (Tcl_CmdProc *)ay_npt_closevtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "clampNPU", ay_npt_clamputcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "clampNPU", (Tcl_CmdProc *)ay_npt_clamputcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "clampNPV", ay_npt_clampvtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "clampNPV", (Tcl_CmdProc *)ay_npt_clampvtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "rescaleKnNP", ay_npt_rescaleknvnptcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "rescaleKnNP", (Tcl_CmdProc *)ay_npt_rescaleknvnptcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "insknNPU", ay_npt_insertknutcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "insknNPU", (Tcl_CmdProc *)ay_npt_insertknutcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "insknNPV", ay_npt_insertknvtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "insknNPV", (Tcl_CmdProc *)ay_npt_insertknvtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "splitNPU", ay_npt_splitutcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "splitNPU", (Tcl_CmdProc *)ay_npt_splitutcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "splitNPV", ay_npt_splitvtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "splitNPV", (Tcl_CmdProc *)ay_npt_splitvtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "extrNP", ay_npt_extractnptcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "extrNP", (Tcl_CmdProc *)ay_npt_extractnptcmd,
+		    NULL, NULL);
 
 /* inform Tcl-context about compile time configuration: */
 
