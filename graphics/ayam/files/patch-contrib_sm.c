--- contrib/sm.c.orig	2007-09-21 13:30:37.000000000 +0200
+++ contrib/sm.c	2007-12-17 19:01:46.000000000 +0100
@@ -473,7 +473,7 @@
  static int countsm = 0;
  char arrname[] = "ayprefs";
  char ffvarname[] = "SMFileFormat", ftvarname[] = "SMFileType";
- char *smfileformat = NULL, *smfiletype = NULL;
+ char *smfileformat, *smfiletype;
 
   if(!o)
     return;
@@ -498,10 +498,10 @@
       return;
     }
 
-  smfiletype = Tcl_GetVar2(ay_interp, arrname, ftvarname,
+  smfiletype = (char *)Tcl_GetVar2(ay_interp, arrname, ftvarname,
 			   TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY);
 
-  smfileformat = Tcl_GetVar2(ay_interp, arrname, ffvarname,
+  smfileformat = (char *)Tcl_GetVar2(ay_interp, arrname, ffvarname,
 			     TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY);
 
   newtrafo->next = trafo;
