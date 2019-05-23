--- microphone.c.orig	2019-05-09 20:49:44 UTC
+++ microphone.c
@@ -76,7 +76,7 @@ static int reverse_tx_sideband;
 
 static int doTxCorrect = 0;				// Corrections for UDP sample transmit
 static double TxCorrectLevel;
-static complex TxCorrectDc;
+static complex double TxCorrectDc;
 
 // Used for the Hermes protocol
 #define HERMES_TX_BUF_SAMPLES	4800	// buffer size in I/Q samples (two shorts)
