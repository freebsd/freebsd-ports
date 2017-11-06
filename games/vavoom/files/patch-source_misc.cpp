--- source/misc.cpp.orig	2010-09-01 20:26:05.000000000 +0200
+++ source/misc.cpp	2017-06-04 09:42:27.118366000 +0200
@@ -119,7 +119,7 @@
 
 void VLogSysError::Serialise(const char* V, EName)
 {
-	Sys_Error(V);
+	Sys_Error("%s", V);
 }
 
 //==========================================================================
@@ -130,7 +130,7 @@
 
 void VLogHostError::Serialise(const char* V, EName)
 {
-	Host_Error(V);
+	Host_Error("%s", V);
 }
 
 //==========================================================================
