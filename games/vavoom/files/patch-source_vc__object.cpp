--- source/vc_object.cpp.orig	2022-12-31 03:37:54 UTC
+++ source/vc_object.cpp
@@ -477,12 +477,12 @@ IMPLEMENT_FUNCTION(VObject, IsDestroyed)
 
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
