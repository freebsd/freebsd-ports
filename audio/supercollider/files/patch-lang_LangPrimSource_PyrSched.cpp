--- lang/LangPrimSource/PyrSched.cpp.orig	2017-03-20 15:18:39 UTC
+++ lang/LangPrimSource/PyrSched.cpp
@@ -38,7 +38,7 @@
 #include <math.h>
 #include <limits>
 
-#if defined(__APPLE__) || defined(__linux__)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
 # include <pthread.h>
 #endif
 
@@ -608,7 +608,7 @@ static void SC_LinuxSetRealtimePriority(pthread_t thre
 
 SCLANG_DLLEXPORT_C void schedRun()
 {
-	thread thread(schedRunFunc);
+	std::thread thread(schedRunFunc);
 	gSchedThread = std::move(thread);
 
 #ifdef __APPLE__
@@ -712,7 +712,7 @@ class TempoClock (public)
 	double mBaseSeconds;
 	double mBaseBeats;
 	bool mRun;
-	thread mThread;
+	std::thread mThread;
 	condition_variable_any mCondition;
 	TempoClock *mPrev, *mNext;
 
@@ -749,7 +749,7 @@ TempoClock::TempoClock(VMGlobals *inVMGlobals, PyrObje
 	mQueue->size = 1;
 	SetInt(&mQueue->count, 0);
 
-	thread thread(std::bind(&TempoClock::Run, this));
+	std::thread thread(std::bind(&TempoClock::Run, this));
 	mThread = std::move(thread);
 
 #ifdef __APPLE__
@@ -777,7 +777,7 @@ TempoClock::TempoClock(VMGlobals *inVMGlobals, PyrObje
 void TempoClock::StopReq()
 {
 	//printf("->TempoClock::StopReq\n");
-	thread stopThread(std::bind(&TempoClock::StopAndDelete, this));
+	std::thread stopThread(std::bind(&TempoClock::StopAndDelete, this));
 	stopThread.detach();
 
 	//printf("<-TempoClock::StopReq\n");
