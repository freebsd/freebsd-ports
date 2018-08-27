--- cpp/src/Ice/ProxyFactory.cpp.orig	2018-04-20 15:02:08 UTC
+++ cpp/src/Ice/ProxyFactory.cpp
@@ -233,6 +233,7 @@ IceInternal::ProxyFactory::checkRetryAft
     }
     else if(cnt > static_cast<int>(_retryIntervals.size()))
     {
+        interval = 0; // apeace compiler
         if(traceLevels->retry >= 1)
         {
             Trace out(logger, traceLevels->retryCat);
