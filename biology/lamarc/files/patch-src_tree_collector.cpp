--- src/tree/collector.cpp.orig	2025-05-18 23:58:39 UTC
+++ src/tree/collector.cpp
@@ -204,7 +204,7 @@ void ParamCollector::AddParamSummary(ForceParameters f
 
 void ParamCollector::AddParamSummary(ForceParameters fp, long ncopy)
 {
-    m_paramsum.push_back(make_pair<ForceParameters, long>(fp, ncopy));
+    m_paramsum.push_back(std::make_pair(fp, ncopy));
 }
 
 //------------------------------------------------------------------------------------
