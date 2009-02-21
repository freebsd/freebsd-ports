--- ./src/ptlib/unix/svcproc.cxx.orig	2009-02-14 22:03:27.000000000 +0100
+++ ./src/ptlib/unix/svcproc.cxx	2009-02-14 22:03:32.000000000 +0100
@@ -165,7 +165,7 @@
 #elif defined(BE_THREADS)
       thread_id tid = ::find_thread(NULL);
 #else
-      unsigned tid = (unsigned) pthread_self();
+      unsigned long tid = (unsigned long)pthread_self();
 #endif
       *out << "ThreadID=0x"
            << setfill('0') << ::hex
@@ -719,12 +719,12 @@
 #elif defined(BE_THREADS)
   thread_id tid = ::find_thread(NULL);
 #else
-  unsigned tid = (unsigned) pthread_self();
+  unsigned long tid = (unsigned long)pthread_self();
 #endif
   PThread * thread_ptr = activeThreads.GetAt(tid);
 
   char msg[200];
-  sprintf(msg, "\nCaught %s, thread_id=%u", sigmsg, tid);
+  sprintf(msg, "\nCaught %s, thread_id=%lu", sigmsg, tid);
 
   if (thread_ptr != NULL) {
     PString thread_name = thread_ptr->GetThreadName();
