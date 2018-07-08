--- src/jtagrw.cc.orig	2018-06-27 21:49:14 UTC
+++ src/jtagrw.cc
@@ -131,7 +131,7 @@ uchar *jtag1::jtagRead(unsigned long add
 	else
 	    numLocations = (numBytes + 1) / 2;
 	if (numLocations > 256)
-	    return false;
+	    return NULL;
 
 	command[1] = whichSpace;
 	command[2] = numLocations - 1;
