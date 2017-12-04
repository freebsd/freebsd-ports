--- src/VBox/Runtime/r0drv/freebsd/time-r0drv-freebsd.c.orig	2016-07-18 11:56:55 UTC
+++ src/VBox/Runtime/r0drv/freebsd/time-r0drv-freebsd.c
@@ -40,16 +40,23 @@
 
 RTDECL(uint64_t) RTTimeNanoTS(void)
 {
-    struct timespec tsp;
-    nanouptime(&tsp);
-    return tsp.tv_sec * RT_NS_1SEC_64
-         + tsp.tv_nsec;
+    struct bintime bt;
+    uint64_t ns;
+    binuptime(&bt);
+    ns = RT_NS_1SEC_64 * bt.sec;
+    ns += (RT_NS_1SEC_64 * (uint32_t)(bt.frac >> 32)) >> 32;
+    return ns;
 }
 
 
 RTDECL(uint64_t) RTTimeMilliTS(void)
 {
-    return RTTimeNanoTS() / RT_NS_1MS;
+    struct bintime bt;
+    uint64_t ms;
+    binuptime(&bt);
+    ms = RT_MS_1SEC_64 * bt.sec;
+    ms += (RT_MS_1SEC_64 * (uint32_t)(bt.frac >> 32)) >> 32;
+    return ms;
 }
 
 
@@ -67,8 +74,7 @@ RTDECL(uint64_t) RTTimeSystemMilliTS(voi
 
 RTDECL(PRTTIMESPEC) RTTimeNow(PRTTIMESPEC pTime)
 {
-    struct timespec tsp;
-    nanotime(&tsp);
-    return RTTimeSpecSetTimespec(pTime, &tsp);
+    struct timespec ts;
+    nanotime(&ts);
+    return RTTimeSpecSetTimespec(pTime, &ts);
 }
-
