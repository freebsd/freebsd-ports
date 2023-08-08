--- desktop/source/app/app.cxx.orig	2022-12-22 00:14:09 UTC
+++ desktop/source/app/app.cxx
@@ -539,6 +539,7 @@ void Desktop::DeInit()
 
 void Desktop::DeInit()
 {
+    const CommandLineArgs& rCmdLineArgs = GetCommandLineArgs();
     try {
         // instead of removing of the configManager just let it commit all the changes
         utl::ConfigManager::storeConfigItems();
@@ -555,7 +556,9 @@ void Desktop::DeInit()
         // clear lockfile
         m_xLockfile.reset();
 
-        RequestHandler::Disable();
+        if ( !rCmdLineArgs.GetUnknown().isEmpty()
+                  || rCmdLineArgs.IsHelp() || rCmdLineArgs.IsVersion() )
+            RequestHandler::Disable();
         if( pSignalHandler )
             osl_removeSignalHandler( pSignalHandler );
     } catch (const RuntimeException&) {
