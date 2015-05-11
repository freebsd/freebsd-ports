--- src/thor/thor.cxx.orig	2015-04-22 15:17:06 UTC
+++ src/thor/thor.cxx
@@ -63,7 +63,7 @@ void thor::tx_init(SoundBase *sc)
 	videoText();
 	strSecXmtText = progdefaults.THORsecText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION " ";
 	cptr = 0;
 }
 
