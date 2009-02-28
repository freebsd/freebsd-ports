--- src/kernel/cpdf.cc.orig	2008-02-22 11:42:07.000000000 +0300
+++ src/kernel/cpdf.cc	2009-02-28 05:38:20.000000000 +0300
@@ -2347,7 +2347,7 @@
 		instance->file = file;
 		kernelPrintDbg(debug::DBG_INFO, "Instance created successfully openMode=" << openMode);
 		return instance;
-	}catch(exception &e)
+	}catch(std::exception &e)
 	{
 		kernelPrintDbg(DBG_CRIT, "Pdf instance creation failed. cause="<<e.what());
 		string what=string("CPdf open failed. reason=")+e.what();
@@ -2631,7 +2631,7 @@
 		try
 		{
 			minPos = getNodePosition(*this, newValue, &nodeCountCache);
-		}catch(exception &e)
+		}catch(std::exception &e)
 		{
 			// position can't be determined
 			// no special handling is needed, minPos keeps its value
@@ -2690,7 +2690,7 @@
 				kernelPrintDbg(DBG_WARN, "page with original position="<<i->first<<" is ambiguous. Invalidating.");
 				// page position is ambiguous and so it has to be invalidate
 				i->second->invalidate();
-			}catch(exception & e)
+			}catch(std::exception & e)
 			{
 				kernelPrintDbg(DBG_CRIT, "Unexpected error. cause="<<e.what());
 				assert(!"Possibly bug.");
