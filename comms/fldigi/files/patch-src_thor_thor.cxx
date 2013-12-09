--- src/thor/thor.cxx.orig	2013-11-16 11:12:26.140977946 -0500
+++ src/thor/thor.cxx	2013-11-16 11:13:27.127067530 -0500
@@ -63,7 +63,7 @@
 	videoText();
 	strSecXmtText = progdefaults.THORsecText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION;
 	cptr = 0;
 }
 
