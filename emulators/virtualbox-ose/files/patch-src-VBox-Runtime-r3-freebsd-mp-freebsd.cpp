--- src/VBox/Runtime/r3/freebsd/mp-freebsd.cpp.orig	2013-11-29 14:24:23.000000000 -0500
+++ src/VBox/Runtime/r3/freebsd/mp-freebsd.cpp	2013-12-13 16:25:44.000000000 -0500
@@ -93,7 +93,7 @@
     char    szDriver[10];
     size_t  cbDriver = sizeof(szDriver);
     RT_ZERO(szDriver);                  /* this shouldn't be necessary. */
-    int rcBsd = sysctlbyname(szName, szDriver, &cbDriver, NULL, NULL);
+    int rcBsd = sysctlbyname(szName, szDriver, &cbDriver, NULL, 0);
     if (rcBsd == 0)
         return true;
 
@@ -154,7 +154,7 @@
         return 0;
 
     /* CPU's have a common frequency. */
-    int rc = sysctlbyname("dev.cpu.0.freq", &uFreqCurr, &cbParameter, NULL, NULL);
+    int rc = sysctlbyname("dev.cpu.0.freq", &uFreqCurr, &cbParameter, NULL, 0);
     if (rc)
         return 0;
 
@@ -176,7 +176,7 @@
      * CPU 0 has the freq levels entry. ENOMEM is ok as we don't need all supported
      * levels but only the first one.
      */
-    int rc = sysctlbyname("dev.cpu.0.freq_levels", szFreqLevels, &cbFreqLevels, NULL, NULL);
+    int rc = sysctlbyname("dev.cpu.0.freq_levels", szFreqLevels, &cbFreqLevels, NULL, 0);
     if (   (rc && (errno != ENOMEM))
         || (cbFreqLevels == 0))
         return 0;
