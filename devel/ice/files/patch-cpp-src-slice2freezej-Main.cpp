--- cpp.orig/src/slice2freezej/Main.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/slice2freezej/Main.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -26,7 +26,7 @@ using namespace IceUtilInternal;
 namespace
 {
 
-IceUtil::Mutex* mutex = 0;
+IceUtil::Mutex* mtx = 0;
 bool interrupted = false;
 
 class Init
@@ -35,13 +35,13 @@ public:
 
     Init()
     {
-        mutex = new IceUtil::Mutex;
+        mtx = new IceUtil::Mutex;
     }
 
     ~Init()
     {
-        delete mutex;
-        mutex = 0;
+        delete mtx;
+        mtx = 0;
     }
 };
 
@@ -52,7 +52,7 @@ Init init;
 void
 interruptedCallback(int signal)
 {
-    IceUtilInternal::MutexPtrLock<IceUtil::Mutex> lock(mutex);
+    IceUtilInternal::MutexPtrLock<IceUtil::Mutex> lock(mtx);
 
     interrupted = true;
 }
@@ -1828,7 +1828,7 @@ compile(int argc, char* argv[])
         }
 
         {
-            IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mutex);
+            IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mtx);
 
             if(interrupted)
             {
@@ -1923,7 +1923,7 @@ compile(int argc, char* argv[])
     u->destroy();
 
     {
-        IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mutex);
+        IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mtx);
 
         if(interrupted)
         {
