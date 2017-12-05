--- ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceUSB.cpp.orig	2017-12-05 15:03:57.734396000 +0300
+++ ThirdParty/BSL430_DLL/BSL430_DLL/Physical_Interfaces/MSPBSL_PhysicalInterfaceUSB.cpp	2017-12-05 15:04:17.062811000 +0300
@@ -189,7 +189,7 @@
 			return ERROR_READING_DATA; 
 		}
 
-		this_thread::sleep_for(chrono::milliseconds(500));
+		this_thread::sleep_for(std::chrono::milliseconds(500));
 	}
 
 	return 0;
