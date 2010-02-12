--- src/SALOMEDSImpl/SALOMEDSImpl_StudyBuilder.cxx.orig	2009-07-20 15:08:45.000000000 +0700
+++ src/SALOMEDSImpl/SALOMEDSImpl_StudyBuilder.cxx	2009-07-20 15:10:26.000000000 +0700
@@ -35,6 +35,7 @@
 #include "DF_Label.hxx"
 
 #include <HDFOI.hxx>
+#include <cstring>
 #include <stdlib.h> 
 
 using namespace std;
