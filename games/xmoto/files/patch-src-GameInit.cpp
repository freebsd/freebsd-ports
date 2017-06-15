--- src/GameInit.cpp.orig	2011-10-11 20:18:35 UTC
+++ src/GameInit.cpp
@@ -248,7 +248,7 @@ void GameApp::run_load(int nNumArgs, cha
   Logger::setActiv(XMSession::instance()->noLog() == false); /* apply log activ mode */
 
   LogInfo(std::string("X-Moto " + XMBuild::getVersionString(true)).c_str());
-  LogInfo("compiled at "__DATE__" "__TIME__);
+  LogInfo("compiled at " __DATE__ " " __TIME__);
   if(SwapEndian::bigendien) {
     LogInfo("Systeme is bigendien");
   } else {
