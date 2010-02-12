--- src/MULTIPR/MULTIPR_Obj.cxx.orig	2009-03-18 20:52:30.000000000 +0600
+++ src/MULTIPR/MULTIPR_Obj.cxx	2009-06-05 14:48:11.000000000 +0700
@@ -742,7 +742,7 @@
   }
 }
 
-ostream& operator<<(ostream& pOs, Obj& pO)
+std::ostream& operator<<(std::ostream& pOs, Obj& pO)
 {
     pOs << "Obj:" << endl;
     pOs << "    Name:" << pO.mMEDfilename << endl;
