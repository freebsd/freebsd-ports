--- lang/LangSource/PyrObject.cpp.orig	2017-03-20 15:18:39 UTC
+++ lang/LangSource/PyrObject.cpp
@@ -1194,7 +1194,7 @@ void buildBigMethodMatrix()
 	double t0 = elapsedTime();
 #endif
 
-	const int hw_concurrency    = thread::hardware_concurrency();
+	const int hw_concurrency    = std::thread::hardware_concurrency();
 	const int cpuCount          = hw_concurrency > 0 ? hw_concurrency    : 1;
 	const int helperThreadCount = cpuCount       > 1 ? cpuCount - 1      : 1;
 	boost::basic_thread_pool pool( helperThreadCount );
