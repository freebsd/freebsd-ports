--- src/las_c_api.cpp.orig	2009-10-02 17:01:59.000000000 +0000
+++ src/las_c_api.cpp
@@ -745,7 +745,7 @@ LAS_DLL LASErrorEnum LASHeader_SetProjec
 
     try {
         liblas::guid id;
-        id = liblas::guid::guid(value);
+        id = liblas::guid(value);
         ((LASHeader*) hHeader)->SetProjectId(id);    
     } catch (std::exception const& e)
     {
@@ -1542,7 +1542,7 @@ LAS_DLL LASGuidH LASGuid_CreateFromStrin
     VALIDATE_LAS_POINTER1(string, "LASGuid_CreateFromString", NULL);    
     liblas::guid id;
     try {
-        id = liblas::guid::guid(string);
+        id = liblas::guid(string);
         return (LASGuidH) new liblas::guid(id);
     }
     catch (std::exception const& e) {
