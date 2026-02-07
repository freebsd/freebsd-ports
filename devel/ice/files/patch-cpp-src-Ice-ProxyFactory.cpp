--- cpp/src/Ice/ProxyFactory.cpp.orig	2019-08-12 19:54:18 UTC
+++ cpp/src/Ice/ProxyFactory.cpp
@@ -242,6 +242,7 @@ IceInternal::ProxyFactory::checkRetryAfterException(co
     } 
     else if(cnt > static_cast<int>(_retryIntervals.size()))
     {
+        interval = 0; // apeace compiler
         if(traceLevels->retry >= 1)
         {
             Trace out(logger, traceLevels->retryCat);
