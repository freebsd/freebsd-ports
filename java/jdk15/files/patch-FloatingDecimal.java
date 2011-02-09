--- ../../j2se/src/share/classes/sun/misc/FloatingDecimal.java.orig	2011-02-08 21:47:56.000000000 -0800
+++ ../../j2se/src/share/classes/sun/misc/FloatingDecimal.java	2011-02-08 21:48:18.000000000 -0800
@@ -1529,7 +1529,7 @@
 		if ( (cmpResult = bigB.cmp( bigD ) ) > 0 ){
 		    overvalue = true; // our candidate is too big.
 		    diff = bigB.sub( bigD );
-		    if ( (bigIntNBits == 1) && (bigIntExp > -expBias) ){
+		    if ( (bigIntNBits == 1) && (bigIntExp > -expBias+1) ){
 			// candidate is a normalized exact power of 2 and
 			// is too big. We will be subtracting.
 			// For our purposes, ulp is the ulp of the
