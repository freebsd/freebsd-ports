--- microphone.c.orig	2016-10-25 20:57:54 UTC
+++ microphone.c
@@ -56,7 +56,7 @@ static int timeVOX = 2000;				// VOX han
 
 static int doTxCorrect = 0;				// Corrections for UDP sample transmit
 static double TxCorrectLevel;
-static complex TxCorrectDc;
+static complex double TxCorrectDc;
 
 // Used for the Hermes protocol
 #define HERMES_TX_BUF_SAMPLES	4800	// buffer size in I/Q samples (two shorts)
