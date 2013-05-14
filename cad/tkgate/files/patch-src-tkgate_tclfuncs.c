--- src/tkgate/tclfuncs.c.orig	2013-05-14 14:50:49.000000000 +0200
+++ src/tkgate/tclfuncs.c	2013-05-14 15:19:00.000000000 +0200
@@ -102,18 +102,19 @@
     hdl_load(es->env);
   else if (strcmp(argv[1],"save") == 0) {
     if (hdl_save(name) < 0)
-      sprintf(tcl->result,"cancel");
+      Tcl_SetResult(tcl, "cancel", TCL_STATIC);
   } else if (strcmp(argv[1],"checksave") == 0) {
-    if (hdl_checkSave(name) < 0)
-      sprintf(tcl->result,"cancel");
+      Tcl_SetResult(tcl, "cancel", TCL_STATIC);
   } else if (strcmp(argv[1],"close") == 0) {
     hdl_close();
   } else if (strcmp(argv[1],"getindex") == 0) {
     int line,pos;
     if (hdl_getCursor(&line,&pos) == 0) {
-      sprintf(tcl->result,"%d.%d",line,pos);
+      char res[127];
+      sprintf(res,"%d.%d",line,pos);
+      Tcl_SetResult(tcl, res, TCL_VOLATILE);
     } else
-      sprintf(tcl->result,"1.0");
+      Tcl_SetResult(tcl, "1.0", TCL_STATIC);
   } else if (strcmp(argv[1],"touch") == 0) {
     ob_touch(TkGate.circuit);			/* Modify somthing to force undo to thing there are changes */
   }
@@ -154,12 +155,12 @@
 static int gat_interface(ClientData _d,Tcl_Interp *tcl,int argc,const char *argv[])
 {
   if (argc < 3) {
-    strcpy(tcl->result,"too few arguments.");
+    Tcl_SetResult(tcl, "too few arguments.", TCL_STATIC);
     return TCL_ERROR;
   }
 
   if (igen_command(argv[1],argv[2],argc-3,argv + 3) != 0) {
-    strcpy(tcl->result,"invalid command.");
+    Tcl_SetResult(tcl, "invalid command.", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -243,7 +244,7 @@
 
   if ((modFlag = Tcl_GetVar(tcl,"tkg_modifiedFlag",TCL_GLOBAL_ONLY)) && *modFlag != '0') {
     DoTcl("File::confDelMods");
-    if (!TkGate.tcl->result || strcmp(TkGate.tcl->result,"yes") != 0) {
+    if (!Tcl_GetStringResult(TkGate.tcl) || strcmp(Tcl_GetStringResult(TkGate.tcl),"yes") != 0) {
       Tcl_SetResult(tcl,"0", TCL_STATIC);
       return TCL_OK;
     }
@@ -308,7 +309,7 @@
   ob_touch(gw->parms->circuit);
 
   if (VerilogOpen(&gw->parms->circuit->es,name,1) < 0) {
-    sprintf(tcl->result,"0");
+    Tcl_SetResult(tcl, "0", TCL_STATIC);
     return TCL_OK;
   }
 
@@ -319,7 +320,7 @@
   FlagRedraw();
 
 
-  sprintf(tcl->result,"1");
+  Tcl_SetResult(tcl, "1", TCL_STATIC);
   return TCL_OK;
 }
 
@@ -330,9 +331,9 @@
     return TCL_OK;
 
   if (SHash_find(TkGate.libraries,argv[1]))
-    sprintf(TkGate.tcl->result,"1");
+    Tcl_SetResult(TkGate.tcl, "1", TCL_STATIC);
   else
-    sprintf(TkGate.tcl->result,"0");
+    Tcl_SetResult(TkGate.tcl, "0", TCL_STATIC);
 
   return TCL_OK;
 }
@@ -547,7 +548,7 @@
   }
 
   if (hdl_checkSave(0) < 0) {		/* Make sure hdl is up to date */
-    sprintf(tcl->result,"cancel");
+    Tcl_SetResult(tcl, "cancel", TCL_STATIC);
     return TCL_OK;
   }
 
@@ -761,11 +762,13 @@
   
   ob_touch(TkGate.circuit);
 
+  char res[127];
   if (argc != 2 || sscanf(argv[1],"%d",&N) != 1) {
     if (argc != 2)
-      sprintf(tcl->result,"argument error argc=%d",argc);
+      sprintf(res,"argument error argc=%d",argc);
     else
-      sprintf(tcl->result,"argument error argv[1]=<%s>",argv[1]);
+      sprintf(res,"argument error argv[1]=<%s>",argv[1]);
+    Tcl_SetResult(tcl, res, TCL_VOLATILE);
     return TCL_ERROR;
   }
 
@@ -804,7 +807,7 @@
 
     if (f) {
       DoTcl("yesno [format [m circ.reallyoverwrite] %s]",fileName);
-      if (strcmp(tcl->result,"yes") != 0)
+      if (strcmp(Tcl_GetStringResult(tcl),"yes") != 0)
 	abortSave = 1;
 
       fclose(f);
@@ -908,7 +911,7 @@
   if (TkGate.circuit->select || TkGate.circuit->mg_selection) {
     sel_delete(es);
     scrollbar_bbx_update();
-  } else if (DoTcl("tkg_getSelectedBlock") == TCL_OK && *tcl->result != 0) {
+  } else if (DoTcl("tkg_getSelectedBlock") == TCL_OK && Tcl_GetStringResult(tcl)[0] != 0) {
     DoTcl("BlockOp::delete");
   } else {
     message(1,msgLookup("err.nodel"));		/* "No deletable selection." */
@@ -985,11 +988,11 @@
 static int gat_computestrhash(ClientData _d,Tcl_Interp *tcl,int argc,const char *argv[])
 {
   if (argc != 2) {
-    sprintf(tcl->result,"wrong number of parameters.");
+    Tcl_SetResult(tcl, "wrong number of parameters.", TCL_STATIC);
     return TCL_ERROR;
   }
 
-  sprintf(tcl->result,"%u",computestrhash(argv[1]));
+  Tcl_SetObjResult(tcl, Tcl_NewLongObj(computestrhash(argv[1])));
   
   return TCL_OK;
 }
@@ -1094,7 +1097,7 @@
   const char *modName;
 
   if (argc != 2) {
-    strcpy(tcl->result,"wrong number of arguments.");
+    Tcl_SetResult(tcl, "wrong number of arguments.", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -1310,7 +1313,7 @@
   Circuit *c = TkGate.circuit;
 
   if (argc != 3) {
-    strcpy(tcl->result,"wrong number of arguments.");
+    Tcl_SetResult(tcl, "wrong number of arguments.", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -1423,7 +1426,7 @@
       }
     }
   } else {
-    strcpy(tcl->result,"bad command.");
+    Tcl_SetResult(tcl, "bad command.", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -1447,7 +1450,7 @@
   GModuleDef *M;
 
   if (argc != 4) {
-    strcpy(tcl->result,"wrong number of arguments.");
+    Tcl_SetResult(tcl, "wrong number of arguments.", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -1468,7 +1471,7 @@
     SetModified(MF_MODULE);
     SynchronizeInterface();
   } else {
-    strcpy(tcl->result,"bad command.");
+    Tcl_SetResult(tcl, "bad command.", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -1560,8 +1563,8 @@
   }
 
   if (strcmp(argv[1],"-all") == 0) {
-    if (DoTcl("tkg_getSelectedBlock") == TCL_OK && *tcl->result != 0)
-      modName = tcl->result;
+    if (DoTcl("tkg_getSelectedBlock") == TCL_OK && Tcl_GetStringResult(tcl)[0] != 0)
+      modName = Tcl_GetStringResult(tcl);
     else if (g && (GCElement_getType(g) == GC_BLOCK || GCElement_getType(g) == GC_SYMBLOCK))
       modName = g->u.block.moduleName;
     else
@@ -1579,7 +1582,7 @@
   /*
    * Scan circuit for instance of module M and update their interfaces.
    */
-  if (strcmp(tcl->result,"yes") == 0) {
+  if (strcmp(Tcl_GetStringResult(tcl),"yes") == 0) {
     Circuit *C =  TkGate.circuit;
     HashElem *he; 
     for (he = Hash_first(C->moduleTable);he;he = Hash_next(C->moduleTable,he)) {
@@ -1965,7 +1968,7 @@
     r = 0;
   }
 
-  sprintf(tcl->result,"%d",r);
+  Tcl_SetObjResult(tcl, Tcl_NewIntObj(r));
   return TCL_OK;
 }
 
@@ -1976,7 +1979,7 @@
   int match = 0;
 
   if (!g) {
-    *tcl->result = 0;
+    Tcl_ResetResult(tcl);
     return TCL_OK;
   }
 
@@ -1991,11 +1994,11 @@
   }
 
   if (!match) {
-    *tcl->result = 0;
+    Tcl_ResetResult(tcl);
     return TCL_OK;
   }
 
-  GSimModule_getFullPath(TkGate.circuit->es->smod,g,tcl->result);
+  GSimModule_getFullPath(TkGate.circuit->es->smod,g,(char *)Tcl_GetStringResult(tcl));
 
   return TCL_OK;
 }
@@ -2097,7 +2100,7 @@
   double timeCorrection;
 
   if (!Scope) {
-    sprintf(tcl->result,"0 0 0 0 ns 0");
+    Tcl_SetResult(tcl, "0 0 0 0 ns 0", TCL_STATIC);
     return TCL_OK;
   }
 
@@ -2130,7 +2133,8 @@
 
   timeCorrection = TkGate.circuit->simulator.si_tsmult/(double)Scope->s_precision;
 
-  sprintf(tcl->result,"%llu %llu %llu %lf %s %llu %llu",
+  char res[128];
+  sprintf(res,"%llu %llu %llu %lf %s %llu %llu",
 	  start,
 	  stop,
 	  Scope->s_range,
@@ -2138,6 +2142,7 @@
 	  SimInterface_unitsToStr(TkGate.circuit->simulator.si_units),
 	  first,
 	  Scope->s_time);
+  Tcl_SetResult(tcl, res, TCL_VOLATILE);
 
   return TCL_OK;
 }
@@ -2159,7 +2164,7 @@
   }
 
   lpp = traceLinesPerPage(orient, paper);
-  sprintf(tcl->result,"%lf",lpp);
+  Tcl_SetObjResult(tcl, Tcl_NewDoubleObj(lpp));
 
   return TCL_OK;
 }
@@ -2200,14 +2205,14 @@
 
 static int gat_getCircProp(ClientData _d,Tcl_Interp *tcl,int argc,const char *argv[])
 {
-  *tcl->result = 0;
+  Tcl_ResetResult(tcl);
 
   if (strcmp(argv[1],"-script") == 0 && argc > 2) {
     int i;
 
     if (sscanf(argv[2],"%d",&i) != 1) return TCL_OK;
     if (i >= TkGate.circuit->numInitScripts) return TCL_OK;
-    strcpy(tcl->result,TkGate.circuit->initScripts[i]);
+    Tcl_SetResult(tcl, TkGate.circuit->initScripts[i], TCL_STATIC);
   }
 
   return TCL_OK;
@@ -2253,6 +2258,7 @@
 
   if (argc != 3) return TCL_OK;
 
+  char res[128];
   if (SimInterface_lookupGate(&TkGate.circuit->simulator,argv[1],&M,&g,&ss) == 0) {
 
     if (M == TkGate.circuit->es->smod) gate_draw(g,0);
@@ -2271,11 +2277,13 @@
 	  g->wires[0]->net->n_nbits,
 	  g->u.sw.dipval);
 
-    sprintf(tcl->result,"%x",g->u.sw.dipval);
+    sprintf(res,"%x",g->u.sw.dipval);
   } else {
-    sprintf(tcl->result,"0");
+    sprintf(res,"0");
   }
 
+  Tcl_SetResult(tcl, res, TCL_VOLATILE);
+
 
   return TCL_OK;
 }
@@ -2349,9 +2357,9 @@
   if (sscanf(argv[1],"%llu",&t) != 1) return TCL_ERROR;
 
   if (tkgate_currentMode() == MM_SIMULATE)
-    SimInterface_formatTime(si, tcl->result, t);
+    SimInterface_formatTime(si, (char *)Tcl_GetStringResult(tcl), t);
   else
-    sprintf(tcl->result,"%llu",t);
+    Tcl_SetObjResult(tcl, Tcl_NewLongObj(t));
 
   return TCL_OK;
 }
@@ -2376,7 +2384,7 @@
   else
     old_mode = 0;
 
-  sprintf(tcl->result,"%d",old_mode);
+  Tcl_SetObjResult(tcl, Tcl_NewIntObj(old_mode));
 
   if (argc > 1) {
     sscanf(argv[1],"%d",&mode);
@@ -2587,11 +2595,11 @@
    */
   if (tkgate_currentMode() == MM_SIMULATE) {
     if (g && GCElement_isModule(g))
-      strcpy(tcl->result,"blksimu");
+      Tcl_SetResult(tcl, "blksimu", TCL_STATIC);
     else if (TkGate.popstate.n)
-      strcpy(tcl->result,"wiresimu");
+      Tcl_SetResult(tcl, "wiresimu", TCL_STATIC);
     else
-      strcpy(tcl->result,"simu");
+      Tcl_SetResult(tcl, "simu", TCL_STATIC);
     return TCL_OK;
   }
 
@@ -2600,9 +2608,9 @@
    */
   if (tkgate_currentMode() == MM_ANALYZE) {
     if (g && GCElement_isModule(g))
-      strcpy(tcl->result,"blkanal");
+      Tcl_SetResult(tcl, "blkanal", TCL_STATIC);
     else
-      strcpy(tcl->result,"anal");
+      Tcl_SetResult(tcl, "anal", TCL_STATIC);
     return TCL_OK;
   }
 
@@ -2612,27 +2620,27 @@
   if (TkGate.circuit->es->isInterface) {
     if (g && GCElement_getType(g) == GC_BLOCK) {
       if (block_hitPort(g,cx,cy))
-	strcpy(tcl->result,"intfblockport");
+	Tcl_SetResult(tcl, "intfblockport", TCL_STATIC);
       else if (block_edgehit(g,x,y))
-	strcpy(tcl->result,"intfblockedge");
+	Tcl_SetResult(tcl, "intfblockedge", TCL_STATIC);
       else
-	strcpy(tcl->result,"intfblock");
+	Tcl_SetResult(tcl, "intfblock", TCL_STATIC);
     } else if (g && GCElement_getType(g) == GC_SYMBLOCK) {
-	strcpy(tcl->result,"intfblock");
+	Tcl_SetResult(tcl, "intfblock", TCL_STATIC);
     } else
-      strcpy(tcl->result,"intf");
+      Tcl_SetResult(tcl, "intf", TCL_STATIC);
 
     return TCL_OK;
   }
     
 
   if (EditState_getMode() != MODE_MOVE && EditState_getMode() != MODE_MOVESEL) {
-    strcpy(tcl->result,"notmove");
+    Tcl_SetResult(tcl, "notmove", TCL_STATIC);
     return TCL_OK;
   }
 
   if (TkGate.circuit->mg_selection && !g)
-    strcpy(tcl->result,"multi");
+    Tcl_SetResult(tcl, "multi", TCL_STATIC);
   else if (g) {
     int N = GCElement_numPads(g);
     int can_add = 0;
@@ -2644,33 +2652,33 @@
 
     if (g->typeinfo->Code == GC_BLOCK) {
       if (block_hitPort(g,cx,cy))
-	strcpy(tcl->result,"blockport");
+        Tcl_SetResult(tcl, "blockport", TCL_STATIC);
       else if (block_edgehit(g,cx,cy))
-	strcpy(tcl->result,"blockedge");
+        Tcl_SetResult(tcl, "blockedge", TCL_STATIC);
       else
-	strcpy(tcl->result,"block");
+        Tcl_SetResult(tcl, "block", TCL_STATIC);
     } else if (g->typeinfo->Code == GC_SYMBLOCK) {
-      strcpy(tcl->result,"block");
+      Tcl_SetResult(tcl, "block", TCL_STATIC);
     } else if (g->typeinfo->Code == GC_JOINT) {
       if (!g->wires[0] || !g->wires[1] || !g->wires[2] || !g->wires[3])
-	strcpy(tcl->result,"joint3");
+	Tcl_SetResult(tcl, "joint3", TCL_STATIC);
       else
-	strcpy(tcl->result,"joint4");
+	Tcl_SetResult(tcl, "joint4", TCL_STATIC);
     } else if (can_add)
-      strcpy(tcl->result,"MIgate");
+      Tcl_SetResult(tcl, "MIgate", TCL_STATIC);
     else
-      strcpy(tcl->result,"gate");
+      Tcl_SetResult(tcl, "gate", TCL_STATIC);
   } else if (TkGate.popstate.n) {
     char *labelCode = TkGate.popstate.n->isLabeled ? "L" : "";
     char *sizeCode = TkGate.popstate.n->showSize ? "S" : "";
 
     if (TkGate.popstate.net && TkGate.popstate.net->n_nbits > 1)
-      sprintf(tcl->result,"mbwire%s%s",labelCode,sizeCode);
+      Tcl_AppendResult(tcl, "mbwire", labelCode, sizeCode, NULL);
     else
-      sprintf(tcl->result,"wire%s",labelCode);
+      Tcl_AppendResult(tcl, "wire", labelCode, NULL);
   }
   else
-    strcpy(tcl->result,"canv");
+    Tcl_SetResult(tcl, "canv", TCL_STATIC);
 
   /*     ob_touch(TkGate.popstate); (popstate may need to be made undoable?) */
 
@@ -2700,7 +2708,7 @@
   int has_plus = 0;
 
   if (argc < 2) {
-    strcpy(tcl->result,"bad mode ");
+    Tcl_SetResult(tcl, "bad mode", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -2716,7 +2724,7 @@
   } else if (strcmp(argv[1],"analyze") == 0) {
     target_mode = MM_ANALYZE;
   }  else {
-    strcpy(tcl->result,"bad mode ");
+    Tcl_SetResult(tcl, "bad mode", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -2760,7 +2768,7 @@
 static int gat_getMajorMode(ClientData _d,Tcl_Interp *tcl,int argc,const char *argv[])
 {
   if (argc != 1) {
-    strcpy(tcl->result,"illegal argument.");
+    Tcl_SetResult(tcl, "illegal argument.", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -2768,16 +2776,16 @@
 
   switch (tkgate_currentMode()) {
     case MM_SIMULATE :
-      strcpy(tcl->result,"simulate");
+      Tcl_SetResult(tcl, "simulate", TCL_STATIC);
       break;
     case MM_EDIT :
       if (editstate_isInterfaceMode())
-	strcpy(tcl->result,"interface");
+        Tcl_SetResult(tcl, "interface", TCL_STATIC);
       else
-	strcpy(tcl->result,"edit");
+        Tcl_SetResult(tcl, "edit", TCL_STATIC);
       break;
     case MM_ANALYZE :
-      strcpy(tcl->result,"analyze");
+      Tcl_SetResult(tcl, "analyze", TCL_STATIC);
       break;
   }
   return TCL_OK;
@@ -2791,7 +2799,7 @@
   GWireNode *wn1,*wn2;
 
   if (argc < 2) {
-    strcpy(tcl->result,"bad cpath");
+    Tcl_SetResult(tcl, "bad cpath", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -2807,7 +2815,7 @@
 
   n = GModuleDef_findNet(TkGate.circuit->es->env,p);
   if (!n) {
-    sprintf(tcl->result,"net '%s' not found.",p);
+    Tcl_AppendResult(tcl, "net '", p, "' not found.", NULL);
     return TCL_ERROR;
   }
 
@@ -2849,7 +2857,7 @@
   GWire *w = 0;
 
   if (argc < 2) {
-    strcpy(tcl->result,"bad popup");
+    Tcl_SetResult(tcl, "bad popup", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -2894,7 +2902,7 @@
   } else if (strcmp(argv[1],"size") == 0) {
     int size;
     if (argc < 3 || sscanf(argv[2],"%d",&size) != 1) {
-      strcpy(tcl->result,"bad port size");
+      Tcl_SetResult(tcl, "bad port size", TCL_STATIC);
       return TCL_ERROR;
     }
     GNet_draw(w->net);
@@ -2914,7 +2922,7 @@
     SetModified(MF_INTERFACE);
     SynchronizeInterface();
   } else {
-    strcpy(tcl->result,"illegal port command.");
+    Tcl_SetResult(tcl, "illegal port command.", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -2926,7 +2934,7 @@
   if (argc > 1)
     sscanf(argv[1],"%d",&TkGate.popstate.isSet);
   else
-    sprintf(tcl->result,"%d",TkGate.popstate.isSet);
+    Tcl_SetObjResult(tcl, Tcl_NewIntObj(TkGate.popstate.isSet));
 
   return TCL_OK;
 }
@@ -3075,11 +3083,10 @@
 static int gat_getTechList(ClientData _d,Tcl_Interp *tcl,int argc,const char *argv[])
 {
   char **techs = GDelayDef_getTechList();
-  char *s,*p;
   int l,i;
 
   if (!techs) {
-    strcpy(TkGate.tcl->result,TKGATE_DEFAULT_TECH);
+    Tcl_SetResult(tcl, TKGATE_DEFAULT_TECH, TCL_STATIC);
     return TCL_OK;
   }
 
@@ -3088,11 +3095,8 @@
     l += strlen(techs[i])+1;
   l++;
 
-  p = s = (char*)ob_malloc(l,"char*");
   for (i = 0;techs[i];i++)
-    p += sprintf(p," %s",techs[i]);
-
-  TkGate.tcl->result = s;
+    Tcl_AppendResult(tcl, " ", techs[i], NULL);
 
   return TCL_OK;
 }
@@ -3147,7 +3151,7 @@
   }
 
   if (!tech) tech = "";
-  strcpy(tcl->result,tech);
+  Tcl_SetResult(tcl, tech, TCL_STATIC);
 
   return TCL_OK;
 }
@@ -3155,7 +3159,7 @@
 static int gat_makeMakeMenu(ClientData _d,Tcl_Interp *tcl,int argc,const char *argv[])
 {
   if (argc != 2) {
-    strcpy(tcl->result,"bad make menu");
+    Tcl_SetResult(tcl, "bad make menu", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -3173,6 +3177,8 @@
  *
  *
  *****************************************************************************/
+int igen_strToSide(const char *side);
+void guessPortName(char *buf,GCElement *g,int orient,int dir,int nbits);
 static int gat_validatePortName(ClientData _d,Tcl_Interp *tcl,int argc,const char *argv[])
 {
   TkgGateWin *gw = TkGate.gw;
@@ -3192,7 +3198,7 @@
 
 
   if (argc < 3) {
-    sprintf(tcl->result,"wrong number of parameters.");
+    Tcl_SetResult(tcl, "wrong number of parameters.", TCL_STATIC);
     return TCL_ERROR;
   }
 
@@ -3254,7 +3260,7 @@
 
   pickValidName(validName,newPortName,"P",curPorts);
 
-  strcpy(tcl->result,validName);
+  Tcl_SetResult(tcl, validName, TCL_VOLATILE);
 
   if (curPorts)
     delete_SHash(curPorts);
@@ -3396,7 +3402,7 @@
   unsigned flags = 0;
 
   if (ob_get_mode() == OM_DISABLED) {
-    sprintf(tcl->result,"0");
+    Tcl_SetResult(tcl, "0", TCL_STATIC);
     return TCL_OK;
   }
 
@@ -3413,7 +3419,7 @@
   else
     ob_begin_framef(argv[1],flags);
 
-  sprintf(tcl->result,"1");
+  Tcl_SetResult(tcl, "1", TCL_STATIC);
 
   return TCL_OK;
 }
@@ -3437,25 +3443,12 @@
 static int gat_getUndoList(ClientData _d,Tcl_Interp *tcl,int argc,const char *argv[])
 {
   const char *undoList[1024];
-  char *p;
   int N,i;
-  int nc = 0;
 
   N = ob_getUndoList(undoList,1024);
 
-
-  nc = 10;
-  for (i = 0;i < N;i++)
-    nc += strlen(undoList[i])+1;
-
-  tcl->result = malloc(nc);	/* Really use malloc/free here */
-  tcl->freeProc = (Tcl_FreeProc*)free;
-
-  p = tcl->result;
-  *p = 0;
   for (i = 0;i < N;i++)
-    p += sprintf(p," %s",undoList[i]);
-
+    Tcl_AppendResult(tcl, " ", undoList[i], NULL);
 
   return TCL_OK;
 }
@@ -3463,24 +3456,12 @@
 static int gat_getRedoList(ClientData _d,Tcl_Interp *tcl,int argc,const char *argv[])
 {
   const char *redoList[1024];
-  char *p;
   int N,i;
-  int nc = 0;
 
   N = ob_getRedoList(redoList,1024);
 
-
-  nc = 10;
-  for (i = 0;i < N;i++)
-    nc += strlen(redoList[i])+1;
-
-  tcl->result = malloc(nc);	/* Really use malloc/free here */
-  tcl->freeProc = (Tcl_FreeProc*)free;
-
-  p = tcl->result;
-  *p = 0;
   for (i = 0;i < N;i++)
-    p += sprintf(p," %s",redoList[i]);
+    Tcl_AppendResult(tcl, " ", redoList[i], NULL);
 
   return TCL_OK;
 }
@@ -3520,19 +3501,16 @@
      * selected since the tcl->result buffer is not expanded as necessary.  However,
      * this features is not currently used, so it should not matter for now.
      */
-    char *p = tcl->result;
     for (E = Hash_first(gs->s_gates);E;E = Hash_next(gs->s_gates,E)) {
       GCElement *g = (GCElement*) HashElem_obj(E);
-      if (p != tcl->result)
-	p += sprintf(p," ");
-      p += sprintf(p,"%s",g->ename);
+      Tcl_AppendResult(tcl, " ", g->ename, NULL);
     }
   } else {
     if (sel_num(TkGate.circuit->es) == 1) {
       GCElement *g = TkGate.circuit->select;
 
       if (g && GCElement_isModule(g)) {
-	strcpy(tcl->result,g->u.block.moduleName);
+        Tcl_SetResult(tcl, g->u.block.moduleName, TCL_VOLATILE);
       }
     }
   }
@@ -3546,7 +3524,7 @@
   
   if (argc == 1) {
     m = ob_get_mode();
-    sprintf(tcl->result,"%d",m);
+    Tcl_SetObjResult(tcl, Tcl_NewIntObj(m));
   } else {
     sscanf(argv[1],"%d",&m);
     ob_mode(m);
