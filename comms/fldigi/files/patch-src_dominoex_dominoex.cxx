--- src/dominoex/dominoex.cxx.orig	2014-03-21 11:25:57.000000000 -0500
+++ src/dominoex/dominoex.cxx	2014-03-21 18:19:42.000000000 -0500
@@ -63,7 +63,7 @@
 
 	strSecXmtText = progdefaults.secText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION;
 
 	videoText();
 }
