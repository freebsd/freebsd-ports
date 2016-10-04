--- modules/core/src/system.cpp.orig	2016-09-16 15:55:58 UTC
+++ modules/core/src/system.cpp
@@ -157,7 +157,7 @@ std::wstring GetTempFileNameWinRT(std::w
 
 #include <stdarg.h>
 
-#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __QNX__
+#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __QNX__ || defined __FreeBSD__
 #include <unistd.h>
 #include <stdio.h>
 #include <sys/types.h>
@@ -942,14 +942,23 @@ struct Mutex::Impl
 
 struct Mutex::Impl
 {
-    Impl() { pthread_mutex_init(&sl, 0); refcount = 1; }
-    ~Impl() { pthread_mutex_destroy(&sl); }
+    Impl()
+    {
+        pthread_mutexattr_t attr;
+        pthread_mutexattr_init(&attr);
+        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
+        pthread_mutex_init(&mt, &attr);
+        pthread_mutexattr_destroy(&attr);
+
+        refcount = 1;
+    }
+    ~Impl() { pthread_mutex_destroy(&mt); }
 
-    void lock() { pthread_mutex_lock(&sl); }
-    bool trylock() { return pthread_mutex_trylock(&sl) == 0; }
-    void unlock() { pthread_mutex_unlock(&sl); }
+    void lock() { pthread_mutex_lock(&mt); }
+    bool trylock() { return pthread_mutex_trylock(&mt) == 0; }
+    void unlock() { pthread_mutex_unlock(&mt); }
 
-    pthread_mutex_t sl;
+    pthread_mutex_t mt;
     int refcount;
 };
 
