--- togl/togl.c.orig	2015-06-23 18:03:50 UTC
+++ togl/togl.c
@@ -709,7 +709,7 @@ int Togl_Init(Tcl_Interp *interp)
    }
 #endif
 
-   Tcl_CreateCommand(interp, "togl", Togl_Cmd,
+   Tcl_CreateCommand(interp, "togl", (Tcl_CmdProc *)Togl_Cmd,
                      (ClientData) Tk_MainWindow(interp), NULL);
    Tcl_InitHashTable(&CommandTable, TCL_STRING_KEYS);
 
@@ -941,7 +941,7 @@ int Togl_Configure(Tcl_Interp *interp, s
    int oldAuxNumber   = togl->AuxNumber;
 
    if (Tk_ConfigureWidget(interp, togl->TkWin, configSpecs,
-                          argc, argv, (char *)togl, flags) == TCL_ERROR) {
+                          argc, (const char **)argv, (char *)togl, flags) == TCL_ERROR) {
       return(TCL_ERROR);
    }
    /*fprintf(stderr,"hier %d %d %d\n", togl->TkWin, togl->Width, togl->Height);*/
@@ -1154,7 +1154,7 @@ static int Togl_Cmd(ClientData clientDat
 
    /* Create command event handler */
    togl->widgetCmd = Tcl_CreateCommand(interp, Tk_PathName(tkwin),
-				       Togl_Widget, (ClientData)togl,
+				       (Tcl_CmdProc *)Togl_Widget, (ClientData)togl,
 				       (Tcl_CmdDeleteProc*) ToglCmdDeletedProc);
    Tk_CreateEventHandler(tkwin,
                          ExposureMask | StructureNotifyMask,
