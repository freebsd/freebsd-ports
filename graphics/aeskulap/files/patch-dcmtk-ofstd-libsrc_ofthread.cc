--- dcmtk/ofstd/libsrc/ofthread.cc.orig	2010-08-23 16:27:34.000000000 +0200
+++ dcmtk/ofstd/libsrc/ofthread.cc	2010-08-23 16:32:49.000000000 +0200
@@ -145,7 +145,7 @@
 #elif defined(POSIX_INTERFACE)
   pthread_t tid=0;
   int result = pthread_create(&tid, NULL, thread_stub, OFstatic_cast(void *, this));
-  if (0 == result) theThread = static_cast<unsigned long>(tid); else theThread = 0;      
+  if (0 == result) theThread = tid; else theThread = 0;      
   return result;     
 #elif defined(SOLARIS_INTERFACE)
   thread_t tid=0;
@@ -174,21 +174,21 @@
 #endif
 }
   
-unsigned long OFThread::threadID()
+pthread_t OFThread::threadID()
 {
   return theThread;
 }
 
 #if defined(WINDOWS_INTERFACE) || defined(POSIX_INTERFACE) || defined(SOLARIS_INTERFACE)
-OFBool OFThread::equal(unsigned long tID)
+OFBool OFThread::equal(pthread_t tID)
 #else
-OFBool OFThread::equal(unsigned long /* tID */ )
+OFBool OFThread::equal(pthread_t /* tID */ )
 #endif
 {
 #ifdef WINDOWS_INTERFACE
   if (theThread == tID) return OFTrue; else return OFFalse;
 #elif defined(POSIX_INTERFACE)
-  if (pthread_equal(static_cast<pthread_t>(theThread), static_cast<pthread_t>(tID))) return OFTrue; else return OFFalse;
+  if (pthread_equal(theThread, tID)) return OFTrue; else return OFFalse;
 #elif defined(SOLARIS_INTERFACE)
   if (OFstatic_cast(thread_t, theThread) == OFstatic_cast(thread_t, tID)) return OFTrue; else return OFFalse;
 #else
@@ -209,12 +209,12 @@
   return; // will never be reached
 }
 
-unsigned long OFThread::self()
+pthread_t OFThread::self()
 {
 #ifdef WINDOWS_INTERFACE
   return OFstatic_cast(unsigned long, GetCurrentThreadId());
 #elif defined(POSIX_INTERFACE)
-  return OFstatic_cast(unsigned long, pthread_self());
+  return pthread_self();
 #elif defined(SOLARIS_INTERFACE)
   return OFstatic_cast(unsigned long, thr_self());
 #else
