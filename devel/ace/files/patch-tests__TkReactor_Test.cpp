--- tests/TkReactor_Test.cpp.orig
+++ tests/TkReactor_Test.cpp
@@ -248,7 +248,7 @@
   tk = Tk_MainWindow(tcl_interp);
   if (tk == 0)
     {
-      ACE_ERROR_RETURN ((LM_ERROR, "Tk_Reactor_Test: %s\n", tcl_interp->result),1);
+      ACE_ERROR_RETURN ((LM_ERROR, "Tk_Reactor_Test: %s\n", Tcl_GetStringResult(tcl_interp)),1);
     }
 
   char tcl_cmd[] = "source TkReactor_Test.tcl";
