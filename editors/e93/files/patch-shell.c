--- shell.c.orig	2013-05-22 09:35:54.000000000 +0200
+++ shell.c	2013-05-22 09:44:04.000000000 +0200
@@ -992,7 +992,7 @@
 		Tcl_SetVar(interpreter,"SCRIPTPATH",scriptPath,TCL_LEAVE_ERR_MSG);
 		if(Tcl_EvalFile(interpreter,scriptPath)!=TCL_OK)
 		{
-			SetError("%s:%d:%s",scriptPath,interpreter->errorLine,Tcl_GetStringResult(interpreter));
+			SetError("%s:%d:%s",scriptPath,Tcl_GetErrorLine(interpreter),Tcl_GetStringResult(interpreter));
 			fail=true;
 		}
 	}
@@ -1066,7 +1066,7 @@
 			}
 			else
 			{
-				SetError("Failed to Tcl_Init(): %s",tclInterpreter->result);
+				SetError("Failed to Tcl_Init(): %s",Tcl_GetStringResult(tclInterpreter));
 			}
 			UnInitChannels(tclInterpreter);
 		}
