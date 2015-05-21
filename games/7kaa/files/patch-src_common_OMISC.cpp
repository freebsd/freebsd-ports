--- src/common/OMISC.cpp.orig	2015-05-19 01:00:20 UTC
+++ src/common/OMISC.cpp
@@ -37,6 +37,7 @@
 #include <stdlib.h>
 #include <time.h>
 #include <ctype.h>
+#include <math.h>
 
 #include <ALL.h>
 #include <OSTR.h>
@@ -755,10 +756,13 @@ char* Misc::format(double inNum, int for
 
    static char outBuf[35];
    char   *outPtr=outBuf;
+   char   floatBuf[35];
    char   *floatStr;
    int    i, intDigit, sign;    // intDigit = no. of integer digits
 
-   floatStr = fcvt( inNum, MONEY_DEC_PLACE, &intDigit, &sign );
+   intDigit = snprintf(floatBuf, sizeof(floatBuf), "%.0lf", fabs(inNum) * 100.0);
+   intDigit -= 2;
+   floatStr = floatBuf;
 
    #ifdef DEBUG
       if( intDigit > 29 )            // integer digits can't exceed 29
