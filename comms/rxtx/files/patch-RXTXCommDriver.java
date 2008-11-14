--- src/RXTXCommDriver.java.orig	2006-01-30 05:37:49.000000000 +0100
+++ src/RXTXCommDriver.java	2008-11-14 13:23:47.000000000 +0100
@@ -590,6 +590,8 @@
 						String[] Temp = {
 							"ttyd",    //general purpose serial ports
 							"cuaa",    //dialout serial ports
+							"ttyU",    //USB serial ports
+							"cuaU",    //USB dialout serial ports
 							"ttyA",    //Specialix SI/XIO dialin ports
 							"cuaA",    //Specialix SI/XIO dialout ports
 							"ttyD",    //Digiboard - 16 dialin ports
