--- src/tkgate/tkgatewin.c.orig	2013-05-14 15:20:45.000000000 +0200
+++ src/tkgate/tkgatewin.c	2013-05-14 15:21:55.000000000 +0200
@@ -941,7 +941,7 @@
       Tk_ConfigSpec *C = &configSpecs[i];
       if (C->type == TK_CONFIG_STRING && strcmp(C->argvName,argv[2]) == 0) {
 	char *value = *(char**)(((char*)gw) + C->offset);
-	strcpy(tcl->result,value);
+    Tcl_SetResult(tcl, value, TCL_VOLATILE);
 	break;
       }
     }
@@ -1071,7 +1071,7 @@
 
   setGCcolors();
 
-  tcl->result = Tk_PathName(w);
+  Tcl_SetResult(tcl, Tk_PathName(w), TCL_STATIC);
 
   return TCL_OK;
 }
@@ -1134,7 +1134,7 @@
   /* Are the objects freed here? */
 
   if (r != TCL_OK) {
-    printf("tkgate: DoTclL Error - %s\n",TkGate.tcl->result);
+    printf("tkgate: DoTclL Error - %s\n",Tcl_GetStringResult(TkGate.tcl));
     printf("   while executing: %s\n",cmd);
   }
 
@@ -1164,7 +1164,7 @@
   /* Are the objects freed here? */
 
   if (r != TCL_OK) {
-    printf("DoTclV Error: %s\n",TkGate.tcl->result);
+    printf("DoTclV Error: %s\n",Tcl_GetStringResult(TkGate.tcl));
     printf("   while executing: %s\n",cmd);
   }
 
