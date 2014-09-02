--- ./modules/core/src/system.cpp.orig	2013-11-25 05:42:32.000000000 -0500
+++ ./modules/core/src/system.cpp	2013-11-25 05:42:42.000000000 -0500
@@ -126,7 +126,7 @@
 
 #include <stdarg.h>
 
-#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__
+#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__ || defined __FreeBSD__
 #include <unistd.h>
 #include <stdio.h>
 #include <sys/types.h>
@@ -897,14 +897,23 @@
 
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
 
-    void lock() { pthread_mutex_lock(&sl); }
-    bool trylock() { return pthread_mutex_trylock(&sl) == 0; }
-    void unlock() { pthread_mutex_unlock(&sl); }
+        refcount = 1;
+    }
+    ~Impl() { pthread_mutex_destroy(&mt); }
 
-    pthread_mutex_t sl;
+    void lock() { pthread_mutex_lock(&mt); }
+    bool trylock() { return pthread_mutex_trylock(&mt) == 0; }
+    void unlock() { pthread_mutex_unlock(&mt); }
+
+    pthread_mutex_t mt;
     int refcount;
 };
 
