--- src/GameInit.cpp.orig	2015-01-10 18:22:36.000000000 +0100
+++ src/GameInit.cpp	2015-01-10 18:27:28.000000000 +0100
@@ -248,7 +248,7 @@ void GameApp::run_load(int nNumArgs, cha
   Logger::setActiv(XMSession::instance()->noLog() == false); /* apply log activ mode */
 
   LogInfo(std::string("X-Moto " + XMBuild::getVersionString(true)).c_str());
-  LogInfo("compiled at "__DATE__" "__TIME__);
+  LogInfo("compiled at " __DATE__ " " __TIME__);
   if(SwapEndian::bigendien) {
     LogInfo("Systeme is bigendien");
   } else {
