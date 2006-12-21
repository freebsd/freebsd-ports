--- sdk/managedthread.h.orig	Thu Dec 21 00:02:41 2006
+++ sdk/managedthread.h	Thu Dec 21 00:03:05 2006
@@ -11,8 +11,8 @@
 class ManagedThread : public wxThread
 {
 public:
-    ManagedThread::ManagedThread(bool* abortflag  = 0L);
-    virtual ManagedThread::~ManagedThread();
+    ManagedThread(bool* abortflag  = 0L);
+    virtual ~ManagedThread();
     static unsigned long count_running();
     static unsigned long count_threads();
     static void abort_all(); // Warning! Once set, can't be reset!
