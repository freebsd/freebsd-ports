--- hk_classes/hk_drivermanager.cpp.orig	Fri Oct 31 12:14:16 2003
+++ hk_classes/hk_drivermanager.cpp	Fri Oct 31 12:14:25 2003
@@ -141,7 +141,7 @@
     {
         if (interactive)
 	{
-	   char* e=dlerror();
+	   const char* e=dlerror();
 	   hk_string error=hk_translate("Unknown reason");
 	   if (e) error=e;
 	   hk_string w=hk_translate("Database driver '%DRIVER%' could not be loaded.\nReason: ")+error;
