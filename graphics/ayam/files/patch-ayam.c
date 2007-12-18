--- ayam.c.orig	2007-09-21 13:30:36.000000000 +0200
+++ ayam.c	2007-12-17 19:12:10.000000000 +0100
@@ -598,227 +598,227 @@
 
   /* aycsg.cpp */
 #ifdef AYCSGWRAPPED
-  Tcl_CreateCommand(interp, "aycsgInit", aycsg_inittcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "aycsgInit", (Tcl_CmdProc *)aycsg_inittcmd,
+		     NULL, NULL);
 #endif
 
   /* clear.c */
-  Tcl_CreateCommand(interp, "newScene", ay_clear_scenetcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "newScene", (Tcl_CmdProc *)ay_clear_scenetcmd,
+		     NULL, NULL);
 
   /* clevel.c */
-  Tcl_CreateCommand(interp, "goTop", ay_clevel_gotoptcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "goTop", (Tcl_CmdProc *)ay_clevel_gotoptcmd,
+		     NULL, NULL);
 
-  Tcl_CreateCommand(interp, "goUp", ay_clevel_gouptcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "goUp", (Tcl_CmdProc *)ay_clevel_gouptcmd,
+		     NULL, NULL);
 
-  Tcl_CreateCommand(interp, "goDown", ay_clevel_godowntcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "goDown", (Tcl_CmdProc *)ay_clevel_godowntcmd,
+		     NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getLevel", ay_clevel_gettcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getLevel", (Tcl_CmdProc *)ay_clevel_gettcmd,
+		     NULL, NULL);
 
   /* clipb.c */
-  Tcl_CreateCommand(interp, "copOb", ay_clipb_copytcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "copOb", (Tcl_CmdProc *)ay_clipb_copytcmd,
+		     NULL, NULL);
 
-  Tcl_CreateCommand(interp, "cutOb", ay_clipb_cuttcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "cutOb", (Tcl_CmdProc *)ay_clipb_cuttcmd,
+		     NULL, NULL);
 
-  Tcl_CreateCommand(interp, "pasOb", ay_clipb_pastetcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "pasOb", (Tcl_CmdProc *)ay_clipb_pastetcmd,
+		     NULL, NULL);
 
-  Tcl_CreateCommand(interp, "cmovOb", ay_clipb_movetcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "cmovOb", (Tcl_CmdProc *)ay_clipb_movetcmd,
+		     NULL, NULL);
 
-  Tcl_CreateCommand(interp, "repOb", ay_clipb_replacetcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "repOb", (Tcl_CmdProc *)ay_clipb_replacetcmd,
+		     NULL, NULL);
 
   /* conv.c */
-  Tcl_CreateCommand(interp, "convOb", ay_convert_forcetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "convOb", (Tcl_CmdProc *)ay_convert_forcetcmd,
+		    NULL, NULL);
 
   /* draw.c */
 
   /* error.c */
-  Tcl_CreateCommand(interp, "ayError", ay_error_tcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "ayError", (Tcl_CmdProc *)ay_error_tcmd,
+		     NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getGLErr", ay_error_getglerrortcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getGLErr", (Tcl_CmdProc *)ay_error_getglerrortcmd,
+		    NULL, NULL);
 
   /* instt.c */
-  Tcl_CreateCommand(interp, "resolveIn", ay_instt_resolvetcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "resolveIn", (Tcl_CmdProc *)ay_instt_resolvetcmd,
+		     NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getMaster", ay_instt_getmastertcmd,
-		     (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getMaster", (Tcl_CmdProc *)ay_instt_getmastertcmd,
+		     NULL, NULL);
 
   /* notify.c */
-  Tcl_CreateCommand(interp, "forceNot", ay_notify_forcetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "forceNot", (Tcl_CmdProc *)ay_notify_forcetcmd,
+		    NULL, NULL);
 
   /* object.c */
-  Tcl_CreateCommand(interp, "crtOb", ay_object_createtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "crtOb", (Tcl_CmdProc *)ay_object_createtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "delOb", ay_object_deletetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "delOb", (Tcl_CmdProc *)ay_object_deletetcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "nameOb", ay_object_setnametcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "nameOb", (Tcl_CmdProc *)ay_object_setnametcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "hasChild", ay_object_haschildtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "hasChild", (Tcl_CmdProc *)ay_object_haschildtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getType", ay_object_gettypetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getType", (Tcl_CmdProc *)ay_object_gettypetcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getName", ay_object_getnametcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getName", (Tcl_CmdProc *)ay_object_getnametcmd,
+		    NULL, NULL);
 
   /* pomesht.c */
-  Tcl_CreateCommand(interp, "mergePo", ay_pomesht_mergetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-  Tcl_CreateCommand(interp, "optiPo", ay_pomesht_optimizetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-  Tcl_CreateCommand(interp, "splitPo", ay_pomesht_splittcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "mergePo", (Tcl_CmdProc *)ay_pomesht_mergetcmd,
+		    NULL, NULL);
+  Tcl_CreateCommand(interp, "optiPo", (Tcl_CmdProc *)ay_pomesht_optimizetcmd,
+		    NULL, NULL);
+  Tcl_CreateCommand(interp, "splitPo", (Tcl_CmdProc *)ay_pomesht_splittcmd,
+		    NULL, NULL);
 
   /* prop.c */
-  Tcl_CreateCommand(interp, "setProp", ay_prop_settcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "setProp", (Tcl_CmdProc *)ay_prop_settcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getProp", ay_prop_gettcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getProp", (Tcl_CmdProc *)ay_prop_gettcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "setTrafo", ay_prop_settrafotcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "setTrafo", (Tcl_CmdProc *)ay_prop_settrafotcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getTrafo", ay_prop_gettrafotcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getTrafo", (Tcl_CmdProc *)ay_prop_gettrafotcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "setAttr", ay_prop_setattrtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "setAttr", (Tcl_CmdProc *)ay_prop_setattrtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getAttr", ay_prop_getattrtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getAttr", (Tcl_CmdProc *)ay_prop_getattrtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "setMat", ay_prop_setmattcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "setMat", (Tcl_CmdProc *)ay_prop_setmattcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getMat", ay_prop_getmattcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getMat", (Tcl_CmdProc *)ay_prop_getmattcmd,
+		    NULL, NULL);
 
   /* prefs.c */
-  Tcl_CreateCommand(interp, "setPrefs", ay_prefs_settcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "setPrefs", (Tcl_CmdProc *)ay_prefs_settcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getPrefs", ay_prefs_gettcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getPrefs", (Tcl_CmdProc *)ay_prefs_gettcmd,
+		    NULL, NULL);
 
   /* read.c */
-  Tcl_CreateCommand(interp, "replaceScene", ay_read_replacetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "replaceScene", (Tcl_CmdProc *)ay_read_replacetcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "insertScene", ay_read_inserttcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "insertScene", (Tcl_CmdProc *)ay_read_inserttcmd,
+		    NULL, NULL);
 
 
   /* sel.c */
-  Tcl_CreateCommand(interp, "selOb", ay_sel_setfromlbtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "selOb", (Tcl_CmdProc *)ay_sel_setfromlbtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getSel", ay_sel_getseltcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getSel", (Tcl_CmdProc *)ay_sel_getseltcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "hSL", ay_sel_hsltcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "hSL", (Tcl_CmdProc *)ay_sel_hsltcmd,
+		    NULL, NULL);
 
 
   /* shader.c */
-  Tcl_CreateCommand(interp, "shaderScanSLC", ay_shader_scanslctcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "shaderScanSLC", (Tcl_CmdProc *)ay_shader_scanslctcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "shaderScanSLX", ay_shader_scanslxtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "shaderScanSLX", (Tcl_CmdProc *)ay_shader_scanslxtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "shaderSet", ay_shader_settcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "shaderSet", (Tcl_CmdProc *)ay_shader_settcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "shaderGet", ay_shader_gettcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "shaderGet", (Tcl_CmdProc *)ay_shader_gettcmd,
+		    NULL, NULL);
 
   /* tags.c */
-  Tcl_CreateCommand(interp, "tagIsTemp", ay_tags_istemptcmd,
-		      (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-  Tcl_CreateCommand(interp, "setTags", ay_tags_settcmd,
-		      (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-  Tcl_CreateCommand(interp, "addTag", ay_tags_addtcmd,
-		      (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-  Tcl_CreateCommand(interp, "getTags", ay_tags_gettcmd,
-		      (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
-  Tcl_CreateCommand(interp, "delTags", ay_tags_deletetcmd,
-		      (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "tagIsTemp", (Tcl_CmdProc *)ay_tags_istemptcmd,
+		      NULL, NULL);
+  Tcl_CreateCommand(interp, "setTags", (Tcl_CmdProc *)ay_tags_settcmd,
+		      NULL, NULL);
+  Tcl_CreateCommand(interp, "addTag", (Tcl_CmdProc *)ay_tags_addtcmd,
+		      NULL, NULL);
+  Tcl_CreateCommand(interp, "getTags", (Tcl_CmdProc *)ay_tags_gettcmd,
+		      NULL, NULL);
+  Tcl_CreateCommand(interp, "delTags", (Tcl_CmdProc *)ay_tags_deletetcmd,
+		      NULL, NULL);
 
   /* tcmd.c */
-  Tcl_CreateCommand(interp, "revert", ay_tcmd_reverttcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "revert", (Tcl_CmdProc *)ay_tcmd_reverttcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "show", ay_tcmd_showtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "show", (Tcl_CmdProc *)ay_tcmd_showtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "hide", ay_tcmd_hidetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "hide", (Tcl_CmdProc *)ay_tcmd_hidetcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getVersion", ay_tcmd_getvertcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getVersion", (Tcl_CmdProc *)ay_tcmd_getvertcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "getPnt", ay_tcmd_getpointtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "getPnt", (Tcl_CmdProc *)ay_tcmd_getpointtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "setPnt", ay_tcmd_setpointtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "setPnt", (Tcl_CmdProc *)ay_tcmd_setpointtcmd,
+		    NULL, NULL);
 
 #ifdef AYENABLEWAIT
-  Tcl_CreateCommand(interp, "waitPid", ay_tcmd_waitpidtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "waitPid", (Tcl_CmdProc *)ay_tcmd_waitpidtcmd,
+		    NULL, NULL);
 #endif /* AYENABLEWAIT */
 
 #ifdef AYENABLEFEXIT
-  Tcl_CreateCommand(interp, "fastExit", ay_tcmd_fastexittcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "fastExit", (Tcl_CmdProc *)ay_tcmd_fastexittcmd,
+		    NULL, NULL);
 #endif /* AYENABLEFEXIT */
 
-  Tcl_CreateCommand(interp, "withOb", ay_tcmd_withobtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "withOb", (Tcl_CmdProc *)ay_tcmd_withobtcmd,
+		    NULL, NULL);
 
   /* tmp.c */
-  Tcl_CreateCommand(interp, "tmpGet", ay_tmp_gettcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "tmpGet", (Tcl_CmdProc *)ay_tmp_gettcmd,
+		    NULL, NULL);
 
   /* trafo.c */
-  Tcl_CreateCommand(interp, "delegTrafo", ay_trafo_delegatetcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "delegTrafo", (Tcl_CmdProc *)ay_trafo_delegatetcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "movOb", ay_trafo_movobtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "movOb", (Tcl_CmdProc *)ay_trafo_movobtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "movSel", ay_trafo_movseltcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "movSel", (Tcl_CmdProc *)ay_trafo_movseltcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "scalOb", ay_trafo_scalobtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "scalOb", (Tcl_CmdProc *)ay_trafo_scalobtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "scalSel", ay_trafo_scalseltcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "scalSel", (Tcl_CmdProc *)ay_trafo_scalseltcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "rotOb", ay_trafo_rotobtcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "rotOb", (Tcl_CmdProc *)ay_trafo_rotobtcmd,
+		    NULL, NULL);
 
-  Tcl_CreateCommand(interp, "rotSel", ay_trafo_rotseltcmd,
-		    (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
+  Tcl_CreateCommand(interp, "rotSel", (Tcl_CmdProc *)ay_trafo_rotseltcmd,
+		    NULL, NULL);
 
   /* oact.c */
   Togl_CreateCommand("moveoac", ay_oact_movetcb);
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
 
