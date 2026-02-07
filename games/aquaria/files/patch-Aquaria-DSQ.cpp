--- Aquaria/DSQ.cpp.orig	2017-12-19 15:08:56 UTC
+++ Aquaria/DSQ.cpp
@@ -2079,7 +2079,7 @@ void DSQ::loadModsCallback(const std::st
 	if(!Mod::loadModXML(&d, name))
 	{
 		std::ostringstream os;
-		os << "Failed to load mod xml: " << filename << " -- Error: " << d.GetErrorStr1();
+		os << "Failed to load mod xml: " << filename << " -- Error: " << d.ErrorStr();
 		dsq->debugLog(os.str());
 		return;
 	}
