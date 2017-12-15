--- src/las_c_api.cpp.orig	2009-10-02 17:48:41 UTC
+++ src/las_c_api.cpp
@@ -745,7 +745,7 @@ LAS_DLL LASErrorEnum LASHeader_SetProjectId(LASHeaderH
 
     try {
         liblas::guid id;
-        id = liblas::guid::guid(value);
+        id = liblas::guid(value);
         ((LASHeader*) hHeader)->SetProjectId(id);    
     } catch (std::exception const& e)
     {
@@ -1542,7 +1542,7 @@ LAS_DLL LASGuidH LASGuid_CreateFromString(const char* 
     VALIDATE_LAS_POINTER1(string, "LASGuid_CreateFromString", NULL);    
     liblas::guid id;
     try {
-        id = liblas::guid::guid(string);
+        id = liblas::guid(string);
         return (LASGuidH) new liblas::guid(id);
     }
     catch (std::exception const& e) {
