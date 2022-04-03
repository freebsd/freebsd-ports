--- src/Controller/Src/KeysValues/All/Resolution.cpp.orig	2021-11-25 00:56:58 UTC
+++ src/Controller/Src/KeysValues/All/Resolution.cpp
@@ -142,7 +142,7 @@ ESDictionary Resolution::GetSeolutionTable(bool isXRes
     ES_CMN_FUNCS::JSON::JSONFiletoDictionary(resTablePath, resTable);
    }else
    {
-    SDI_TRACE_LOG("resolution faile does not found");
+    SDI_TRACE_LOG("resolution file not found");
    }
   }
   catch (boost::bad_any_cast) {
