--- src/gnu/io/RXTXCommDriver.java.orig	2011-03-07 01:33:36.824057319 -0700
+++ src/gnu/io/RXTXCommDriver.java	2011-03-07 01:33:39.527398898 -0700
@@ -648,6 +648,10 @@
 						String[] Temp = {
 							"ttyd",    //general purpose serial ports
 							"cuaa",    //dialout serial ports
+							"ttyu",    //general purpose serial ports (uart)
+							"cuau",    //dialout serial ports (uart)
+							"ttyU",    //USB serial ports
+							"cuaU",    //USB dial in serial ports
 							"ttyA",    //Specialix SI/XIO dialin ports
 							"cuaA",    //Specialix SI/XIO dialout ports
 							"ttyD",    //Digiboard - 16 dialin ports
