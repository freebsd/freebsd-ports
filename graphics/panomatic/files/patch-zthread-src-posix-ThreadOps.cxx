--- zthread/src/posix/ThreadOps.cxx.orig	2008-02-28 22:51:46.000000000 +0000
+++ zthread/src/posix/ThreadOps.cxx	2012-09-24 12:02:46.539117586 +0000
@@ -103,7 +103,7 @@
   struct sched_param param;
   int policy = SCHED_OTHER;
   
-  if(result = (pthread_getschedparam(impl->_tid, &policy, &param) == 0)) {
+  if((result = (pthread_getschedparam(impl->_tid, &policy, &param) == 0))) {
     
     // Convert to one of the PRIORITY values
     if(param.sched_priority < 10)
