--- microphone.c.orig	2018-11-21 19:08:22 UTC
+++ microphone.c
@@ -58,7 +58,7 @@ static int timeVOX = 2000;				// VOX han
 
 static int doTxCorrect = 0;				// Corrections for UDP sample transmit
 static double TxCorrectLevel;
-static complex TxCorrectDc;
+static complex double TxCorrectDc;
 
 // Used for the Hermes protocol
 #define HERMES_TX_BUF_SAMPLES	4800	// buffer size in I/Q samples (two shorts)
