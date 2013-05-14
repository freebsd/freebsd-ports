--- src/tkgate/locale.c.orig	2013-05-14 14:46:02.000000000 +0200
+++ src/tkgate/locale.c	2013-05-14 14:46:35.000000000 +0200
@@ -395,10 +395,7 @@
   if (argc < 2) return TCL_OK;
 
   msg = msgLookup(argv[1]);
-  if (strlen(msg) < 127)
-    strcpy(tcl->result,msg);
-  else
-    tcl->result = strdup(msg);
+  Tcl_SetResult(tcl, msg, TCL_VOLATILE);
 
   return TCL_OK;
 }
