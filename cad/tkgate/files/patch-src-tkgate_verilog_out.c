--- src/tkgate/verilog_out.c.orig	2013-05-14 15:22:29.000000000 +0200
+++ src/tkgate/verilog_out.c	2013-05-14 15:22:51.000000000 +0200
@@ -1071,7 +1071,7 @@
 	unlink(tempName1);
 	unlink(tempName2);
 	DoTcl("yesno [format [m err.nosafesave] %s]",name);
-	if (strcmp(TkGate.tcl->result,"yes") == 0)
+	if (strcmp(Tcl_GetStringResult(TkGate.tcl),"yes") == 0)
 	  VerilogQuickSave(name,saveFlags);
 	return 0;
       }
