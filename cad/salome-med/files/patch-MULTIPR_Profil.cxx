--- src/MULTIPR/MULTIPR_Profil.cxx.orig	2009-03-18 20:52:30.000000000 +0600
+++ src/MULTIPR/MULTIPR_Profil.cxx	2009-06-05 14:20:37.000000000 +0700
@@ -41,6 +41,9 @@
 using namespace std;
 
 
+
+
+
 namespace multipr
 {
 
@@ -344,7 +347,7 @@
 }
 
 
-ostream& operator<<(ostream& pOs, Profil& pP)
+std::ostream& operator<<(std::ostream& pOs, Profil& pP)
 {
     pOs << "Profil:" << endl;
     pOs << "    Name=|" << pP.mName << "|" << endl;
