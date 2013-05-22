--- shellcmd.c.orig	2013-05-22 09:45:47.000000000 +0200
+++ shellcmd.c	2013-05-22 09:46:25.000000000 +0200
@@ -6354,7 +6354,7 @@
 					{
 						if(tclResult!=TCL_OK)
 						{
-							sprintf(tempString,"Error in line %d: ",localInterpreter->errorLine);
+							sprintf(tempString,"Error in line %d: ",Tcl_GetErrorLine(localInterpreter));
 							EditorAuxInsert(buffer,(UINT8 *)tempString,(UINT32)strlen(tempString));
 						}
 						EditorAuxInsert(buffer,(UINT8 *)stringResult,(UINT32)strlen(stringResult));
