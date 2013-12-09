--- src/dominoex/dominoex.cxx.orig	2013-05-14 05:06:28.000000000 -0400
+++ src/dominoex/dominoex.cxx	2013-11-16 11:17:10.251959725 -0500
@@ -64,7 +64,7 @@
 
 	strSecXmtText = progdefaults.secText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION;
 
 	videoText();
 }
