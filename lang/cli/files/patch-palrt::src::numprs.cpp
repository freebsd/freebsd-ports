--- palrt/src/numprs.cpp.orig	Tue Aug 12 18:49:14 2003
+++ palrt/src/numprs.cpp	Tue Aug 12 18:49:28 2003
@@ -41,7 +41,7 @@
 //
 #define MAXEXP (INT_MAX/2)
 
-const SPLIT64    sdlTenToEighteen = { {UI64(1000000000000000000)} };
+const SPLIT64    sdlTenToEighteen = { UI64(1000000000000000000) };
 // Max value of Decimal (= 79228162514264337593543950335), less 1st digit.
 const BYTE rgbMaxDec[DEC_MAXDIG - 1] = {9,2,2,8,1,6,2,5,1,4,2,6,4,3,3,7,5,9,3,5,4,3,9,5,0,3,3,5};
 
