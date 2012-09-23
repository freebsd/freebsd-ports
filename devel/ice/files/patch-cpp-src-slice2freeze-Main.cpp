--- cpp.orig/src/slice2freeze/Main.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/slice2freeze/Main.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -28,7 +28,7 @@ using namespace Slice;
 namespace
 {
 
-IceUtil::Mutex* mutex = 0;
+IceUtil::Mutex* mtx = 0;
 bool interrupted = false;
 
 class Init
@@ -37,13 +37,13 @@ public:
 
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
 
@@ -56,7 +56,7 @@ string ICE_ENCODING_COMPARE = "Freeze::IceEncodingCompare";
 void
 interruptedCallback(int signal)
 {
-    IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mutex);
+    IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mtx);
 
     interrupted = true;
 }
@@ -1995,7 +1995,7 @@ compile(int argc, char* argv[])
         }
 
         {
-            IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mutex);
+            IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mtx);
 
             if(interrupted)
             {
@@ -2042,7 +2042,7 @@ compile(int argc, char* argv[])
     u->destroy();
 
     {
-        IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mutex);
+        IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mtx);
 
         if(interrupted)
         {
