--- src/MULTIPR/MULTIPR_MeshDis.cxx.orig	2009-03-18 20:52:30.000000000 +0600
+++ src/MULTIPR/MULTIPR_MeshDis.cxx	2009-06-05 14:19:02.000000000 +0700
@@ -179,7 +179,7 @@
 }
 
 
-ostream& operator<<(ostream& pOs, MeshDisPart& pM)
+std::ostream& operator<<(std::ostream& pOs, MeshDisPart& pM)
 {
     switch (pM.mToDoOnNextWrite)
     {
@@ -1475,7 +1475,7 @@
     }
 }
 
-ostream& operator<<(ostream& pOs, MeshDis& pM)
+std::ostream& operator<<(std::ostream& pOs, MeshDis& pM)
 {
     pOs << "Mesh Dis.:" << endl;
     pOs << "    Sequential filename (source) =|" << pM.mSequentialMEDFilename << "|" << endl;
