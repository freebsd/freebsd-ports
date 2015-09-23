--- utests/utest.cpp.orig	2015-08-26 12:00:07.664830000 +0200
+++ utests/utest.cpp	2015-08-26 12:00:37.039946000 +0200
@@ -44,6 +44,7 @@
 RStatistics UTest::retStatistics;
 
 void releaseUTestList(void) { delete UTest::utestList; }
+__attribute__((destructor))
 void runSummaryAtExit(void) {
   // If case crashes, count it as fail, and accumulate finishrun
   if(UTest::retStatistics.finishrun != UTest::utestList->size()) {
@@ -113,7 +114,6 @@
     utestList = new vector<UTest>;
 
     catch_signal();
-    atexit(runSummaryAtExit);
   }
   utestList->push_back(*this);
 }
