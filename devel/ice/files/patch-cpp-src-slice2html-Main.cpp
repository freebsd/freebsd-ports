--- cpp.orig/src/slice2html/Main.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/slice2html/Main.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -24,7 +24,7 @@ using namespace IceUtil;
 namespace
 {
 
-IceUtil::Mutex* mutex = 0;
+IceUtil::Mutex* mtx = 0;
 bool interrupted = false;
 
 class Init
@@ -33,13 +33,13 @@ public:
 
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
 
@@ -50,7 +50,7 @@ Init init;
 void
 interruptedCallback(int signal)
 {
-    IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mutex);
+    IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mtx);
 
     interrupted = true;
 }
@@ -254,7 +254,7 @@ compile(int argc, char* argv[])
         }
 
         {
-            IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mutex);
+            IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mtx);
 
             if(interrupted)
             {
@@ -296,7 +296,7 @@ compile(int argc, char* argv[])
     p->destroy();
 
     {
-        IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mutex);
+        IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mtx);
 
         if(interrupted)
         {
