--- shell.c.orig	2009-12-26 20:34:58 UTC
+++ shell.c
@@ -1070,7 +1070,7 @@ static bool InitTcl(char *pathName)
 			}
 			else
 			{
-				SetError("Failed to Tcl_Init(): %s",Tcl_GetResult(tclInterpreter));
+				SetError("Failed to Tcl_Init(): %s",Tcl_GetStringResult(tclInterpreter));
 			}
 			UnInitChannels(tclInterpreter);
 		}
