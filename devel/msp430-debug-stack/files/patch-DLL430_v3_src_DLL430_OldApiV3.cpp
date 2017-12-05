--- DLL430_v3/src/DLL430_OldApiV3.cpp.orig	2017-12-05 18:38:46.037302000 +0300
+++ DLL430_v3/src/DLL430_OldApiV3.cpp	2017-12-05 18:40:21.357777000 +0300
@@ -191,7 +191,7 @@ void DLL430_OldApiV3::event(DebugEventTa
 			//With trace/variable watch enabled, give storage events on same trigger time to be reported
 			if (trace_storage.trControl == TR_ENABLE)
 			{
-				this_thread::sleep_for(chrono::milliseconds(100));
+				this_thread::sleep_for(std::chrono::milliseconds(100));
 			}
 			db_man->pausePolling();
 		}
@@ -1524,7 +1524,7 @@ bool DLL430_OldApiV3::Erase(int32_t type
 				log(LogTarget::ERR, ERASE_ERR, "");
 				return false;
 			}
-			this_thread::sleep_for(chrono::seconds(1));
+			this_thread::sleep_for(std::chrono::seconds(1));
 			return true;
 			
 		}
@@ -1538,7 +1538,7 @@ bool DLL430_OldApiV3::Erase(int32_t type
 			}
 			if (singleDevice)
 			{
-				this_thread::sleep_for(chrono::seconds(1));
+				this_thread::sleep_for(std::chrono::seconds(1));
 				return true;
 			}
 		}
@@ -1923,7 +1923,7 @@ bool DLL430_OldApiV3::Reset(int32_t meth
 		if (devArchitecture != MSP432_M4)
 		{
 			db_man->resumePolling();
-			this_thread::sleep_for(chrono::milliseconds(500));
+			this_thread::sleep_for(std::chrono::milliseconds(500));
 			db_man->pausePolling();
 		}
 		if (!State(&state, true, &pCPUCycles))
@@ -3781,7 +3781,7 @@ bool DLL430_OldApiV3::FET_FwUpdate(
 
 			if (!handle)
 			{
-				this_thread::sleep_for(chrono::seconds(3));
+				this_thread::sleep_for(std::chrono::seconds(3));
 				this->Initialize(&port[0], &version);
 			}
 
@@ -4179,7 +4179,7 @@ bool DLL430_OldApiV3::writeToExternalMem
 
 	Run(FREE_RUN, true);					// start execution of loader code
 
-	this_thread::sleep_for(chrono::seconds(15));
+	this_thread::sleep_for(std::chrono::seconds(15));
 
 	int32_t state;
 	int32_t pCPUCycles;
