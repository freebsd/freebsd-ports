--- src/Controller/Src/KeysValues/All/Resolution.cpp.orig	2024-09-12 07:10:35 UTC
+++ src/Controller/Src/KeysValues/All/Resolution.cpp
@@ -145,7 +145,7 @@ ESDictionary Resolution::GetSeolutionTable(bool isXRes
     ES_CMN_FUNCS::JSON::JSONFiletoDictionary(resTablePath, resTable);
    }else
    {
-    SDI_TRACE_LOG("resolution faile does not found");
+    SDI_TRACE_LOG("resolution file not found");
    }
   }
   catch (boost::bad_any_cast) {
