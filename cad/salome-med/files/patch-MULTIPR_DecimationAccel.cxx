--- src/MULTIPR/MULTIPR_DecimationAccel.cxx.orig	2009-03-18 20:52:30.000000000 +0600
+++ src/MULTIPR/MULTIPR_DecimationAccel.cxx	2009-06-05 14:46:47.000000000 +0700
@@ -51,7 +51,7 @@
 //*****************************************************************************
 
 
-ostream& operator<<(ostream& pOs, DecimationAccel& pA)
+std::ostream& operator<<(std::ostream& pOs, DecimationAccel& pA)
 {
     pOs << "DecimationAccel:" << endl;
     return pOs;
@@ -305,7 +305,7 @@
 }
 
 
-ostream& operator<<(ostream& pOs, DecimationAccelGrid& pG)
+std::ostream& operator<<(std::ostream& pOs, DecimationAccelGrid& pG)
 {
     pOs << "DecimationAccelGrid:" << endl;
     pOs << "    Num=" << pG.mNum << endl;
