--- SpiralSound/PluginManager.C.orig	2003-08-08 13:07:30 UTC
+++ SpiralSound/PluginManager.C
@@ -49,7 +49,7 @@ PluginID PluginManager::LoadPlugin(const
     }
 		
 	// Link the neccesary functions 
-	char *error;
+	const char *error;
 	
 	NewPlugin->CreateInstance  = (SpiralPlugin*(*)()) dlsym(NewPlugin->Handle, "SpiralPlugin_CreateInstance"); 	
 	
@@ -98,7 +98,7 @@ void PluginManager::UnLoadPlugin(PluginI
 	if (IsValid(ID))
     {
 		dlclose(GetPlugin(ID)->Handle);
-		char *error;				
+		const char *error;				
 	    if ((error = dlerror()) != NULL)
 	    {
 			SpiralInfo::Alert("Error unlinking plugin: \n"+string(error));
@@ -112,7 +112,7 @@ void PluginManager::UnloadAll()
 		 i!=m_PluginVec.end(); i++)
 	{		
 		dlclose((*i)->Handle);
-		char *error;				
+		const char *error;				
 	    if ((error = dlerror()) != NULL)
 	    {
 			SpiralInfo::Alert("Error unlinking plugin: \n"+string(error));
