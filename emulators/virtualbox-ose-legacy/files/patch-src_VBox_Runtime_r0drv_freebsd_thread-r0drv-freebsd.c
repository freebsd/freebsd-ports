--- src/VBox/Runtime/r0drv/freebsd/thread-r0drv-freebsd.c.orig	2016-07-18 11:56:55 UTC
+++ src/VBox/Runtime/r0drv/freebsd/thread-r0drv-freebsd.c
@@ -49,7 +49,6 @@ RTDECL(RTNATIVETHREAD) RTThreadNativeSel
 static int rtR0ThreadFbsdSleepCommon(RTMSINTERVAL cMillies)
 {
     int rc;
-    int cTicks;
 
     /*
      * 0 ms sleep -> yield.
@@ -65,6 +64,21 @@ static int rtR0ThreadFbsdSleepCommon(RTM
      */
     if (cMillies != RT_INDEFINITE_WAIT)
     {
+#if __FreeBSD_version >= 1000029
+        struct timeval tv;
+
+        tv.tv_sec = cMillies / 1000;
+        tv.tv_usec = cMillies * 1000;
+
+        rc = tsleep_sbt((void *)RTThreadSleep,
+                        PZERO | PCATCH,
+                        "iprtsl",       /* max 6 chars */
+                        tvtosbt(tv),
+                        0,
+                        C_ABSOLUTE);
+#else
+        int cTicks;
+
         if (hz == 1000)
             cTicks = cMillies;
         else if (hz == 100)
@@ -76,14 +90,23 @@ static int rtR0ThreadFbsdSleepCommon(RTM
             if (cTicks != cTicks64)
                 cTicks = INT_MAX;
         }
+        if (!cTicks)
+            cTicks = 1;
+
+        rc = tsleep((void *)RTThreadSleep,
+                    PZERO | PCATCH,
+                    "iprtsl",           /* max 6 chars */
+                    cTicks);
+#endif
     }
     else
-        cTicks = 0;     /* requires giant lock! */
-
-    rc = tsleep((void *)RTThreadSleep,
-                PZERO | PCATCH,
-                "iprtsl",           /* max 6 chars */
-                cTicks);
+    {
+        /* requires giant lock! */
+        rc = tsleep((void *)RTThreadSleep,
+                    PZERO | PCATCH,
+                    "iprts0",           /* max 6 chars */
+                    0);
+    }
     switch (rc)
     {
         case 0:
