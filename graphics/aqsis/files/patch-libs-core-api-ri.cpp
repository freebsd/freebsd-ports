--- libs/core/api/ri.cpp.orig	2012-02-20 18:29:00.000000000 +0300
+++ libs/core/api/ri.cpp	2012-02-20 18:29:35.000000000 +0300
@@ -488,12 +488,12 @@
 
 	// Read in the system configuration file.
 	boost::filesystem::path systemRcPath = rootPath / AQSIS_XSTR(AQSIS_MAIN_CONFIG_NAME);
-	std::ifstream rcFile(systemRcPath.file_string().c_str(), std::ios::binary);
+	std::ifstream rcFile(systemRcPath.string().c_str(), std::ios::binary);
 	if(rcFile)
 	{
 		Aqsis::log() << info
 			<< "Reading system config \"" << systemRcPath << "\"\n";
-		QGetRenderContext()->parseRibStream(rcFile, systemRcPath.file_string());
+		QGetRenderContext()->parseRibStream(rcFile, systemRcPath.string());
 		rcFile.close();
 	}
 	else
@@ -508,22 +508,22 @@
 		boost::filesystem::path homeRcPath = homePath;
 		homeRcPath /= ".aqsisrc";
 
-		std::ifstream rcFile(homeRcPath.file_string().c_str(), std::ios::binary);
+		std::ifstream rcFile(homeRcPath.string().c_str(), std::ios::binary);
 		if(rcFile)
 		{
 			Aqsis::log() << info << "Reading user config \"" << homeRcPath << "\"\n";
-			QGetRenderContext()->parseRibStream(rcFile, homeRcPath.file_string());
+			QGetRenderContext()->parseRibStream(rcFile, homeRcPath.string());
 		}
 		else
 		{
 			boost::filesystem::path homeRcPath2 = homePath;
 			homeRcPath2 /= "_aqsisrc";
 		
-			std::ifstream rcFile(homeRcPath2.file_string().c_str(), std::ios::binary);
+			std::ifstream rcFile(homeRcPath2.string().c_str(), std::ios::binary);
 			if(rcFile)
 			{
 				Aqsis::log() << info << "Reading user config \"" << homeRcPath2 << "\"\n";
-				QGetRenderContext()->parseRibStream(rcFile, homeRcPath2.file_string());
+				QGetRenderContext()->parseRibStream(rcFile, homeRcPath2.string());
 			}
 			else
 			{
