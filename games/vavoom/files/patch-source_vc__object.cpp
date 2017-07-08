--- source/vc_object.cpp.orig	2010-06-04 23:20:21.000000000 +0200
+++ source/vc_object.cpp	2017-06-04 09:43:20.120992000 +0200
@@ -477,12 +477,12 @@
 
 IMPLEMENT_FUNCTION(VObject, Error)
 {
-	Host_Error(*PF_FormatString());
+	Host_Error("%s", *PF_FormatString());
 }
 
 IMPLEMENT_FUNCTION(VObject, FatalError)
 {
-	Sys_Error(*PF_FormatString());
+	Sys_Error("%s", *PF_FormatString());
 }
 
 //**************************************************************************
