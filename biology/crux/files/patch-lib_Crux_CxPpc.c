--- lib/Crux/CxPpc.c.orig	2009-09-19 04:31:04 UTC
+++ lib/Crux/CxPpc.c
@@ -8,14 +8,11 @@ bool CxgPpcUseAltivec;
 void
 CxPpcCpuInit(void)
 {
-    int mib[2];
     int result, error;
     size_t len;
 
-    mib[0] = CTL_HW;
-    mib[1] = HW_VECTORUNIT;
     len = sizeof(result);
-    error = sysctl(mib, 2, &result, &len, NULL, 0);
+    error = sysctlbyname("hw.altivec", &result, &len, NULL, 0);
     if (error != 0)
     {
 	CxgPpcUseAltivec = false;
