--- src/pcConfig.c.orig	2003-03-26 03:23:38.000000000 -0500
+++ src/pcConfig.c	2011-08-03 18:58:36.000000000 -0400
@@ -155,7 +155,7 @@
 {
     if (target == (char *) &ControlBarShow)
 	ControlBarFix();
-    else if (target == (char *) &ToolBarType || target == (char *) ToolBarShow)
+    else if (target == (char *) &ToolBarType || target == (char *) &ToolBarShow)
 	StatusShowMessage(_("Use menu instead!"));
     else if (Term)
     {
@@ -180,8 +180,8 @@
 		MouseRightButtonNum = 3;
 	    }
 	}
-	else if (target == (char *) ModemMaxHistory
-		 || target == (char *) ModemHistoryBufSize)
+	else if (target == (char *) &ModemMaxHistory
+		 || target == (char *) &ModemHistoryBufSize)
 	    ModemHistoryNew();
     }
 }
