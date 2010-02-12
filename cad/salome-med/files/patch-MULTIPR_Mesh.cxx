--- src/MULTIPR/MULTIPR_Mesh.cxx.orig	2009-03-18 20:52:30.000000000 +0600
+++ src/MULTIPR/MULTIPR_Mesh.cxx	2009-06-05 14:19:22.000000000 +0700
@@ -1909,7 +1909,7 @@
 }
 
 
-ostream& operator<<(ostream& pOs, Mesh& pM)
+std::ostream& operator<<(std::ostream& pOs, Mesh& pM)
 {
     pOs << "Mesh: " << endl;
     pOs << "    MED file =|" << pM.mMEDfilename << "|" << endl;
