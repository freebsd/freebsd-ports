--- src/MULTIPR/MULTIPR_Nodes.cxx.orig	2009-05-28 22:08:56.000000000 +0700
+++ src/MULTIPR/MULTIPR_Nodes.cxx	2009-07-13 13:29:35.000000000 +0700
@@ -36,6 +36,8 @@
 #include "MULTIPR_Exceptions.hxx"
 
 #include <iostream>
+#include <cstring>
+#include <memory>
 #include <limits>
 
 using namespace std;
@@ -429,7 +431,7 @@
 }
 
 
-ostream& operator<<(ostream& pOs, Nodes& pN)
+std::ostream& operator<<(std::ostream& pOs, Nodes& pN)
 {
     char strCoordSystem[16];
     switch (pN.mCoordSystem) 
