From ae11c0b24fd3be995185ebdc5a5bbbb92ff30843 Mon Sep 17 00:00:00 2001
From: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date: Tue, 10 Sep 2013 17:50:56 +0300
Subject: [PATCH] ffmpeg: Rename `mutex' to `g_mutex'.

std::mutex is an actual type in C++11 and is implemented by libc++. The
build was failing because references to `mutex' in lockmgr were ambiguous,
as both the mutex variable defined above and std::mutex (because of the
`using namespace std' statement) were found.
---
 plugins/endplugins/ffmpegendanalyzer.cpp | 14 +++++++-------
 1 file changed, 7 insertions(+), 7 deletions(-)

diff --git a/plugins/endplugins/ffmpegendanalyzer.cpp b/plugins/endplugins/ffmpegendanalyzer.cpp
index f219912..eaed07f 100644
--- libstreamanalyzer/plugins/endplugins/ffmpegendanalyzer.cpp
+++ libstreamanalyzer/plugins/endplugins/ffmpegendanalyzer.cpp
@@ -56,22 +56,22 @@ public:
     signed char analyze(AnalysisResult& idx, ::InputStream* in);
 };
 
-STRIGI_MUTEX_DEFINE(mutex);
+STRIGI_MUTEX_DEFINE(g_mutex);
 
 static int
 lockmgr(void **mtx, enum AVLockOp op) {
   // pre-allocating a single mutex is the only way to get it to work without changing strigi_thread.h
-  assert( (*mtx == &mutex) || (op == AV_LOCK_CREATE) );
+  assert( (*mtx == &g_mutex) || (op == AV_LOCK_CREATE) );
   switch(op) {
   case AV_LOCK_CREATE:
-    *mtx = &mutex;
-    return !!STRIGI_MUTEX_INIT(&mutex);
+    *mtx = &g_mutex;
+    return !!STRIGI_MUTEX_INIT(&g_mutex);
   case AV_LOCK_OBTAIN:
-    return !!STRIGI_MUTEX_LOCK(&mutex);
+    return !!STRIGI_MUTEX_LOCK(&g_mutex);
   case AV_LOCK_RELEASE:
-    return !!STRIGI_MUTEX_UNLOCK(&mutex);
+    return !!STRIGI_MUTEX_UNLOCK(&g_mutex);
   case AV_LOCK_DESTROY:
-    STRIGI_MUTEX_DESTROY(&mutex);
+    STRIGI_MUTEX_DESTROY(&g_mutex);
     return 0;
   }
   return 1;
-- 
1.8.4

