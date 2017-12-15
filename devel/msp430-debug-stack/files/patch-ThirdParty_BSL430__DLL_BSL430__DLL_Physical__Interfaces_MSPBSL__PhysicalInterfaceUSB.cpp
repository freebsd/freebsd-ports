--- ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceUSB.cpp.orig	2017-12-05 18:47:14.538669000 +0300
+++ ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceUSB.cpp	2017-12-05 18:47:14.575461000 +0300
@@ -189,7 +189,7 @@ uint16_t MSPBSL_PhysicalInterfaceUSB::RX
 			return ERROR_READING_DATA; 
 		}
 
-		this_thread::sleep_for(chrono::milliseconds(500));
+		this_thread::sleep_for(std::chrono::milliseconds(500));
 	}
 
 	return 0;
