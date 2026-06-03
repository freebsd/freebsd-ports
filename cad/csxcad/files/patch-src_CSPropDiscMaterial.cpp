--- src/CSPropDiscMaterial.cpp.orig	2026-03-02 05:14:03 UTC
+++ src/CSPropDiscMaterial.cpp
@@ -26,6 +26,9 @@
 #include "ParameterCoord.h"
 #include "CSPropDiscMaterial.h"
 
+#include <iostream>
+
+
 CSPropDiscMaterial::CSPropDiscMaterial(ParameterSet* paraSet) : CSPropMaterial(paraSet)
 {
 	Type=(CSProperties::PropertyType)(DISCRETE_MATERIAL | MATERIAL);
@@ -327,7 +330,7 @@ bool CSPropDiscMaterial::ReadHDF5( std::string filenam
 
 bool CSPropDiscMaterial::ReadHDF5( std::string filename )
 {
-	cout << __func__ << ": Reading \"" << filename << "\"" << std::endl;
+	std::cout << __func__ << ": Reading \"" << filename << "\"" << std::endl;
 
 	// open hdf5 file
 	hid_t file_id = H5Fopen( filename.c_str(), H5F_ACC_RDONLY, H5P_DEFAULT );
