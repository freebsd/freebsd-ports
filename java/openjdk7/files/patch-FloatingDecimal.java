--- jdk/src/share/classes/sun/misc/FloatingDecimal.java.orig	2010-06-21 14:15:30.000000000 -0700
+++ jdk/src/share/classes/sun/misc/FloatingDecimal.java	2011-02-08 22:30:49.000000000 -0800
@@ -1547,7 +1547,7 @@
                 if ( (cmpResult = bigB.cmp( bigD ) ) > 0 ){
                     overvalue = true; // our candidate is too big.
                     diff = bigB.sub( bigD );
-                    if ( (bigIntNBits == 1) && (bigIntExp > -expBias) ){
+                    if ( (bigIntNBits == 1) && (bigIntExp > -expBias+1) ){
                         // candidate is a normalized exact power of 2 and
                         // is too big. We will be subtracting.
                         // For our purposes, ulp is the ulp of the
