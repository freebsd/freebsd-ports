--- src/ptlib/unix/svcproc.cxx.orig	Mon Mar 12 17:03:44 2007
+++ src/ptlib/unix/svcproc.cxx	Mon Mar 12 17:04:53 2007
@@ -388,7 +388,7 @@
 #elif defined(BE_THREADS)
       thread_id tid = ::find_thread(NULL);
 #else
-      unsigned tid = (unsigned) pthread_self();
+      unsigned long tid = (unsigned long) pthread_self();
 #endif
       *out << "ThreadID=0x"
            << setfill('0') << ::hex
@@ -938,12 +938,12 @@
 #elif defined(BE_THREADS)
   thread_id tid = ::find_thread(NULL);
 #else
-  unsigned tid = (unsigned) pthread_self();
+  unsigned long tid = (unsigned long) pthread_self();
 #endif
   PThread * thread_ptr = activeThreads.GetAt(tid);
 
   char msg[200];
-  sprintf(msg, "\nCaught %s, thread_id=%u", sigmsg, tid);
+  sprintf(msg, "\nCaught %s, thread_id=%xu", sigmsg, tid);
 
   if (thread_ptr != NULL) {
     PString thread_name = thread_ptr->GetThreadName();
