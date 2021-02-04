--- desktop/source/app/app.cxx.orig	2020-11-22 14:05:28 UTC
+++ desktop/source/app/app.cxx
@@ -524,6 +524,7 @@ void Desktop::InitFinished()
 
 void Desktop::DeInit()
 {
+    const CommandLineArgs& rCmdLineArgs = GetCommandLineArgs();
     try {
         // instead of removing of the configManager just let it commit all the changes
         utl::ConfigManager::storeConfigItems();
@@ -540,7 +541,9 @@ void Desktop::DeInit()
         // clear lockfile
         m_xLockfile.reset();
 
-        RequestHandler::Disable();
+        if ( !rCmdLineArgs.GetUnknown().isEmpty()
+                  || rCmdLineArgs.IsHelp() || rCmdLineArgs.IsVersion() )
+            RequestHandler::Disable();
         if( pSignalHandler )
             osl_removeSignalHandler( pSignalHandler );
     } catch (const RuntimeException&) {
