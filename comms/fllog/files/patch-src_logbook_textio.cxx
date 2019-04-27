--- src/logbook/textio.cxx.orig	2019-04-25 08:17:16 UTC
+++ src/logbook/textio.cxx
@@ -74,7 +74,7 @@ void cTextFile::writeCSVHeader(FILE *txtFile)
 	if (btnSelectBand->value())      fprintf (txtFile, "%s", ",\"BAND\"");
 	if (btnSelectFreq->value())      fprintf (txtFile, "%s", ",\"FREQ\"");
 	if (btnSelectMode->value())      fprintf (txtFile, "%s", ",\"MODE\"");
-	if (btnSelectMode->value())      fprintf (txtFile, "%s", ",\SUB_MODE\"");
+	if (btnSelectMode->value())      fprintf (txtFile, "%s", ",\"SUB_MODE\"");
 	if (btnSelectTX_pwr->value())    fprintf (txtFile, "%s", ",\"TX_PWR\"");
 	if (btnSelectRSTsent->value())   fprintf (txtFile, "%s", ",\"RSTSENT\"");
 	if (btnSelectRSTrcvd->value())   fprintf (txtFile, "%s", ",\"RSTRCVD\"");
