--- cpp/src/Ice/ProxyFactory.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/src/Ice/ProxyFactory.cpp
@@ -237,6 +237,7 @@ IceInternal::ProxyFactory::checkRetryAfterException(co
     }
     else if(cnt > static_cast<int>(_retryIntervals.size()))
     {
+        interval = 0; // apeace compiler
         if(traceLevels->retry >= 1)
         {
             Trace out(logger, traceLevels->retryCat);
