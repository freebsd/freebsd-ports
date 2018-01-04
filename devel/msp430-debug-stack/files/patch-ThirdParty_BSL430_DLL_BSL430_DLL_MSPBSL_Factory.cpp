--- ThirdParty/BSL430_DLL/BSL430_DLL/MSPBSL_Factory.cpp.orig	2017-12-05 18:38:46.036313000 +0300
+++ ThirdParty/BSL430_DLL/BSL430_DLL/MSPBSL_Factory.cpp	2017-12-05 18:39:50.453006000 +0300
@@ -212,7 +212,7 @@ MSPBSL_Connection* MSPBSL_Factory::getMS
 		bool isOpen = s->physicalInterfaceCommand(ENUMERATE_COMMAND) == 0;
 		while (s && !isOpen && retries-- > 0)
 		{
-			this_thread::sleep_for(chrono::seconds(2));
+			this_thread::sleep_for(std::chrono::seconds(2));
 			isOpen = s->physicalInterfaceCommand(ENUMERATE_COMMAND) == 0;
 		}
 		if (!isOpen)
