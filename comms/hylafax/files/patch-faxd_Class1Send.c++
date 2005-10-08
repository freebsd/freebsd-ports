--- faxd/Class1Send.c++.orig	Sat Oct  8 18:06:03 2005
+++ faxd/Class1Send.c++	Sat Oct  8 18:06:47 2005
@@ -270,6 +270,8 @@
     HDLCFrame frame(conf.class1FrameOverhead);
 
     do {
+        hadV34Trouble = false;		// to monitor failure type
+	batchingError = false;
 	signalRcvd = 0;
 	if (abortRequested())
 	    return (send_failed);
@@ -320,8 +322,6 @@
 	/*
 	 * Transmit the facsimile message/Phase C.
 	 */
-        hadV34Trouble = false;		// to monitor failure type
-	batchingError = false;
 	if (!sendPage(tif, params, decodePageChop(pph, params), cmd, emsg)) {
 	    if (hadV34Trouble) {
 		protoTrace("The destination appears to have trouble with V.34-Fax.");
@@ -913,6 +913,7 @@
 	ecmBlock[ecmBlockPos++] = ecmFrame[i];
     ecmFramePos = 0;
     if (frameNumber == 256 || lastframe) {
+	fxAssert(frameNumber <= 256, "Invalid frameNumber value.");
 	ecmBlockPos = 0;
 	bool lastblock = lastframe;
 
@@ -1145,7 +1146,7 @@
 			}
 		    }
 		}
-	    } while (!gotppr && (++ppscnt < 3) && (crpcnt < 3));
+	    } while (!gotppr && (++ppscnt < 3) && (crpcnt < 3) && !(useV34 && gotEOT));
 	    if (gotppr) {
 		if (!useV34 && !atCmd(conf.class1SwitchingCmd, AT_OK)) {
 		    emsg = "Failure to receive silence.";
@@ -1485,9 +1486,11 @@
 		return (false);
 	}
     }
-    if (eod && (ecmFramePos != 0)) {
-	while (ecmFramePos < (frameSize + 4))
-	    ecmFrame[ecmFramePos++] = 0x00;
+    if (eod) {
+	if (ecmFramePos != 0)	{
+	    // frame must be filled to end with zero-data
+	    while (ecmFramePos < (frameSize + 4)) ecmFrame[ecmFramePos++] = 0x00;
+	}
 	if (!blockFrame(bitrev, true, ppmcmd, emsg))
 	    return (false);
     }
@@ -1631,7 +1634,7 @@
     }
 
     bool rc = true;
-    ecmBlockPos = ecmFramePos = ecmBitPos = ecmOnes = ecmByte = 0;
+    frameNumber = ecmBlockPos = ecmFramePos = ecmBitPos = ecmOnes = ecmByte = 0;
     protoTrace("SEND begin page");
 
     tstrip_t nstrips = TIFFNumberOfStrips(tif);
