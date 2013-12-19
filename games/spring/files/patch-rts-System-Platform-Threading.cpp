--- rts/System/Platform/Threading.cpp.orig	2013-03-26 03:58:36.000000000 +0400
+++ rts/System/Platform/Threading.cpp	2013-11-09 00:13:03.263078447 +0400
@@ -39,7 +39,7 @@
 	static boost::thread::id simThreadID;
 	static boost::thread::id batchThreadID;
 #endif	
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #elif defined(WIN32)
 	static DWORD cpusSystem = 0;
 #else
@@ -52,7 +52,7 @@
 		if (inited)
 			return;
 		
-	#if defined(__APPLE__)
+	#if defined(__APPLE__) || defined(__FreeBSD__)
 		// no-op
 
 	#elif defined(WIN32)
@@ -76,7 +76,7 @@
 			return ~0;
 		}
 
-	#if defined(__APPLE__)
+	#if defined(__APPLE__) || defined(__FreeBSD__)
 		// no-op
 
 	#elif defined(WIN32)
@@ -151,7 +151,7 @@
 	boost::uint32_t GetAvailableCoresMask()
 	{
 		boost::uint32_t systemCores = 0;
-	#if defined(__APPLE__)
+	#if defined(__APPLE__) || defined(__FreeBSD__)
 		// no-op
 		systemCores = ~0;
 
@@ -269,7 +269,7 @@
 
 	void SetThreadScheduler()
 	{
-	#if defined(__APPLE__)
+	#if defined(__APPLE__) || defined(__FreeBSD__)
 		// no-op
 
 	#elif defined(WIN32)
