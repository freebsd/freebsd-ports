
$FreeBSD$

--- src/af/xap/unix/xap_UnixFrame.cpp	2001/08/08 15:59:48	1.1
+++ src/af/xap/unix/xap_UnixFrame.cpp	2001/08/08 16:06:14
@@ -767,9 +767,19 @@
 		fmtstring = "khelpcenter %s &";
 		execstring = g_strdup_printf(fmtstring, szURL);
 	}
-	else
+	else if(progExists("gnome-help-browser"))
+	{
+		fmtstring = "gnome-help-browser %s &";
+		execstring = g_strdup_printf(fmtstring, szURL);
+	}
+	else if(progExists("lynx"))
 	{
 		fmtstring = "xterm -e lynx %s &";
+		execstring = g_strdup_printf(fmtstring, szURL);
+	}
+	else if(progExists("w3m"))
+	{
+		fmtstring = "xterm -e w3m %s &";
 		execstring = g_strdup_printf(fmtstring, szURL);
 	}
 
