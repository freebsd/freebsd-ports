--- SpiralSound/PluginManager.C.orig	Mon Jan  6 01:17:04 2003
+++ SpiralSound/PluginManager.C	Mon Jan  6 01:17:45 2003
@@ -48,7 +48,7 @@
     }
 		
 	// Link the neccesary functions 
-	char *error;
+	const char *error;
 	
 	NewPlugin->CreateInstance  = (SpiralPlugin*(*)()) dlsym(NewPlugin->Handle, "CreateInstance"); 	
 	
@@ -89,7 +89,7 @@
 	if (IsValid(ID))
     {
 		dlclose(GetPlugin(ID)->Handle);
-		char *error;				
+		const char *error;				
 	    if ((error = dlerror()) != NULL)
 	    {
 			SpiralInfo::Alert("Error unlinking plugin: \n"+string(error));
@@ -103,7 +103,7 @@
 		 i!=m_PluginVec.end(); i++)
 	{		
 		dlclose((*i)->Handle);
-		char *error;				
+		const char *error;				
 	    if ((error = dlerror()) != NULL)
 	    {
 			SpiralInfo::Alert("Error unlinking plugin: \n"+string(error));
