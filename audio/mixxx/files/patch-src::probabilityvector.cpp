--- src/probabilityvector.cpp.orig	Fri Jun 25 19:36:10 2004
+++ src/probabilityvector.cpp	Fri Jun 25 19:36:33 2004
@@ -18,6 +18,7 @@
 #include "probabilityvector.h"
 #include "mathstuff.h"
 #include "qapplication.h"
+#include "compat_round.h"
 
 ProbabilityVector::ProbabilityVector(float fMinInterval, float fMaxInterval, int iBins)
 {
@@ -55,7 +56,7 @@
 
         for (float j=fStart; j<fEnd; j++)
         {
-            int idx = round((fCenter+j));
+            int idx = compat_round((fCenter+j));
             m_pHist[idx] += exp((-0.5*j*j)/(0.5*(CSAMPLE)kiGaussWidth))*fValue; //*fHysterisisFactor;
             if (m_pHist[idx]>m_pHist[m_iCurrMaxBin])
             {
