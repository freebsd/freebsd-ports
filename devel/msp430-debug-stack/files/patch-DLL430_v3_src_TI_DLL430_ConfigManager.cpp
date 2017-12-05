--- DLL430_v3/src/TI/DLL430/ConfigManager.cpp.orig	2017-12-05 18:47:14.461686000 +0300
+++ DLL430_v3/src/TI/DLL430/ConfigManager.cpp	2017-12-05 18:47:14.601264000 +0300
@@ -135,7 +135,7 @@ void ConfigManager::init ()
 		iniFile = string(iniPathEnv) + "/" + iniFile;
 	}
 
-	ifstream DllV3Ini(iniFile.c_str());
+	std::ifstream DllV3Ini(iniFile.c_str());
 
 	while (DllV3Ini && !DllV3Ini.eof())
 	{
@@ -259,9 +259,9 @@ bool ConfigManager::jtagErase(uint16_t e
 		return false;
 	}
 #if defined(_WIN32) || defined(_WIN64) ||  defined(__APPLE__)
-	this_thread::sleep_for(chrono::milliseconds(100));
+	this_thread::sleep_for(std::chrono::milliseconds(100));
 #else
-	this_thread::sleep_for(chrono::milliseconds(500));
+	this_thread::sleep_for(std::chrono::milliseconds(500));
 #endif
 	return true;
 }
@@ -561,7 +561,7 @@ bool ConfigManager::reset(bool vcc, bool
 				return false;
 			}
 			// keep voltage 0 for minmum 5 seconds
-			this_thread::sleep_for(chrono::seconds(5));
+			this_thread::sleep_for(std::chrono::seconds(5));
 
 			if (!this->setDeviceVcc(voltage))
 			{
@@ -622,7 +622,7 @@ bool ConfigManager::reset(bool vcc, bool
 				return false;
 			}
 			// keep voltate 0 for minmum 5 seconds
-			this_thread::sleep_for(chrono::seconds(5));
+			this_thread::sleep_for(std::chrono::seconds(5));
 			if (!this->setDeviceVcc(voltage))
 			{
 				return false;
@@ -718,10 +718,10 @@ bool ConfigManager::setVccEzFet(uint16_t
 	#if defined(_WIN32) || defined(_WIN64) ||  defined(__APPLE__)
 		if (vcc)
 		{
-			this_thread::sleep_for(chrono::milliseconds(500));
+			this_thread::sleep_for(std::chrono::milliseconds(500));
 		}
 	#else
-		this_thread::sleep_for(chrono::milliseconds(1000));
+		this_thread::sleep_for(std::chrono::milliseconds(1000));
 	#endif
 
 	}
@@ -789,9 +789,9 @@ bool ConfigManager::setVccMspFET(uint16_
 		}
 
 	#if defined(_WIN32) || defined(_WIN64) ||  defined(__APPLE__)
-		this_thread::sleep_for(chrono::milliseconds(100));
+		this_thread::sleep_for(std::chrono::milliseconds(100));
 	#else
-		this_thread::sleep_for(chrono::milliseconds(700));
+		this_thread::sleep_for(std::chrono::milliseconds(700));
 	#endif
 
 		// now run calibration to support Energy Trace
@@ -822,9 +822,9 @@ bool ConfigManager::setVccMspFET(uint16_
 			return false;
 		}
 	#if defined(_WIN32) || defined(_WIN64) ||  defined(__APPLE__)
-		this_thread::sleep_for(chrono::milliseconds(100));
+		this_thread::sleep_for(std::chrono::milliseconds(100));
 	#else
-		this_thread::sleep_for(chrono::milliseconds(700));
+		this_thread::sleep_for(std::chrono::milliseconds(700));
 	#endif
 
 		// Send power down command to Sub mcu Firmware
@@ -858,10 +858,10 @@ bool ConfigManager::setVccMspFetUif(uint
 	#if defined(_WIN32) || defined(_WIN64) ||  defined(__APPLE__)
 		if (vcc)
 		{
-			this_thread::sleep_for(chrono::milliseconds(1000));
+			this_thread::sleep_for(std::chrono::milliseconds(1000));
 		}
 	#else
-			this_thread::sleep_for(chrono::milliseconds(2500));
+			this_thread::sleep_for(std::chrono::milliseconds(2500));
 	#endif
 		return true;
 }
