--- ./src/GPSInterface_Serial.cpp.orig	2007-10-09 04:02:14.000000000 +0200
+++ ./src/GPSInterface_Serial.cpp	2014-03-24 12:27:07.000000000 +0100
@@ -243,7 +243,7 @@
 				
 				// Echo DeLorme Tripmate's and Earthmate's hello message
 				LibRoadnavDebug1(wxT("SerialIO"), wxT("Echoing hello message: %s"), strSentence.c_str());
-				sprintf(szOut, "%s\r\n", strSentence.mb_str(*wxConvCurrent));
+				sprintf(szOut, "%s\r\n", static_cast<const char *>(strSentence.mb_str(*wxConvCurrent)));
 				WriteSerial(szOut);
 			}
 			else if (!VerifyGPSChecksum(strSentence)) // check NMEA validity
