--- DLL430_v3/src/DLL430_OldApiV3.cpp.orig	2018-03-26 17:21:18.500487000 +0300
+++ DLL430_v3/src/DLL430_OldApiV3.cpp	2018-03-26 17:22:50.850255000 +0300
@@ -191,7 +191,7 @@
 			//With trace/variable watch enabled, give storage events on same trigger time to be reported
 			if (trace_storage.trControl == TR_ENABLE)
 			{
-				this_thread::sleep_for(chrono::milliseconds(100));
+				this_thread::sleep_for(std::chrono::milliseconds(100));
 			}
 			db_man->pausePolling();
 		}
@@ -330,7 +330,7 @@
 	catch (const std::runtime_error& e)
 	{
 #ifndef NDEBUG
-		ofstream("xml_error.log") << e.what() << endl;
+		std::ofstream("xml_error.log") << e.what() << endl;
 #endif
 		log(LogTarget::ERR, DEVICE_DB_ERR, e.what());
 		return false;
@@ -356,7 +356,7 @@
 	catch (const std::runtime_error& e)
 	{
 #ifndef NDEBUG
-		ofstream("xml_error.log") << e.what() << endl;
+		std::ofstream("xml_error.log") << e.what() << endl;
 #endif
 		log(LogTarget::ERR, DEVICE_DB_ERR, e.what());
 		return false;
@@ -1569,7 +1569,7 @@
 				log(LogTarget::ERR, ERASE_ERR, "");
 				return false;
 			}
-			this_thread::sleep_for(chrono::seconds(1));
+			this_thread::sleep_for(std::chrono::seconds(1));
 			return true;
 			
 		}
@@ -1583,7 +1583,7 @@
 			}
 			if (singleDevice)
 			{
-				this_thread::sleep_for(chrono::seconds(1));
+				this_thread::sleep_for(std::chrono::seconds(1));
 				return true;
 			}
 		}
@@ -1987,7 +1987,7 @@
 		if (devArchitecture != MSP432_M4)
 		{
 			db_man->resumePolling();
-			this_thread::sleep_for(chrono::milliseconds(500));
+			this_thread::sleep_for(std::chrono::milliseconds(500));
 			db_man->pausePolling();
 		}
 		if (!State(&state, true, &pCPUCycles))
@@ -3848,7 +3848,7 @@
 				int timeout = 50;
 				while (timeout-- && !this->Initialize(&port[0], &version))
 				{
-					this_thread::sleep_for(chrono::seconds(1));
+					this_thread::sleep_for(std::chrono::seconds(1));
 				}
 				if (!handle)
 				{
@@ -3873,7 +3873,7 @@
 #endif
 						UpdateLog.append("\n---------------------Firmware upate end--------------------------\n");
 
-						ofstream(logfile.c_str(), ios::app | ios::out) << UpdateLog;
+						std::ofstream(logfile.c_str(), ios::app | ios::out) << UpdateLog;
 					}
 				}
 			}
@@ -4272,7 +4272,7 @@
 
 	Run(FREE_RUN, true);					// start execution of loader code
 
-	this_thread::sleep_for(chrono::seconds(15));
+	this_thread::sleep_for(std::chrono::seconds(15));
 
 	int32_t state;
 	int32_t pCPUCycles;
