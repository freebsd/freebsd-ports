--- utests/utest.cpp.orig	2017-01-20 10:40:51 UTC
+++ utests/utest.cpp
@@ -52,6 +52,7 @@ vector<int> v;
 RStatistics UTest::retStatistics;
 
 void releaseUTestList(void) { delete UTest::utestList; }
+__attribute__((destructor))
 void runSummaryAtExit(void) {
   // If case crashes, count it as fail, and accumulate finishrun
   if(UTest::retStatistics.finishrun != UTest::utestList->size()) {
@@ -146,7 +147,6 @@ UTest::UTest(Function fn, const char *na
     utestList = new vector<UTest>;
 
     catch_signal();
-    atexit(runSummaryAtExit);
   }
   utestList->push_back(*this);
 }
