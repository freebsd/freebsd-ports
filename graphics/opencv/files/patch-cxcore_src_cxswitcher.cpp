--- cxcore/src/cxswitcher.cpp   Mon Feb 28 16:34:30 2005
+++ cxcore/src/cxswitcher.cpp.freebsd   Mon Feb 28 16:34:17 2005
@@ -593,8 +593,8 @@
         QueryPerformanceCounter( &counter );
         return (int64)counter.QuadPart;
 #else
-        timeval tv;
-        timezone tz;
+        struct timeval tv; // patch for FreeBSD: add "struct"
+        struct timezone tz; // patch for FreeBSD: add "struct"
         gettimeofday( &tv, &tz );
         return (int64)tv.tv_sec*1000000 + tv.tv_usec;
 #endif

