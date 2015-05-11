--- src/dominoex/dominoex.cxx.orig	2015-04-22 15:17:06 UTC
+++ src/dominoex/dominoex.cxx
@@ -63,7 +63,7 @@ void dominoex::tx_init(SoundBase *sc)
 
 	strSecXmtText = progdefaults.secText;
 	if (strSecXmtText.length() == 0)
-		strSecXmtText = "fldigi "PACKAGE_VERSION" ";
+		strSecXmtText = "fldigi " PACKAGE_VERSION;
 
 	videoText();
 }
