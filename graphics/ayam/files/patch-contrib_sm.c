--- contrib/sm.c.orig	2016-01-13 20:09:57 UTC
+++ contrib/sm.c
@@ -474,7 +474,7 @@ ay_sm_wriballsm(char *file, char *objfil
  static int countsm = 0;
  char arrname[] = "ayprefs";
  char ffvarname[] = "SMFileFormat", ftvarname[] = "SMFileType";
- char *smfileformat = NULL, *smfiletype = NULL;
+ char *smfileformat, *smfiletype;
 
   if(!o)
     return;
@@ -499,10 +499,10 @@ ay_sm_wriballsm(char *file, char *objfil
       return;
     }
 
-  smfiletype = Tcl_GetVar2(ay_interp, arrname, ftvarname,
+  smfiletype = (char *)Tcl_GetVar2(ay_interp, arrname, ftvarname,
 			   TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY);
 
-  smfileformat = Tcl_GetVar2(ay_interp, arrname, ffvarname,
+  smfileformat = (char *)Tcl_GetVar2(ay_interp, arrname, ffvarname,
 			     TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY);
 
   newtrafo->next = trafo;
