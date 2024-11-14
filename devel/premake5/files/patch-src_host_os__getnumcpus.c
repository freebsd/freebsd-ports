--- src/host/os_getnumcpus.c.orig	2024-11-14 13:12:15 UTC
+++ src/host/os_getnumcpus.c
@@ -46,29 +46,8 @@ int do_getnumcpus()
 	{
 		return 0;
 	}
-#elif PLATFORM_SOLARIS | PLATFORM_AIX | PLATFORM_MACOSX
+#elif PLATFORM_SOLARIS | PLATFORM_AIX | PLATFORM_MACOSX | PLATFORM_BSD
 	return sysconf(_SC_NPROCESSORS_ONLN);
-#elif PLATFORM_BSD
-	int mib[4];
-	int numCPU;
-	size_t len = sizeof(numCPU);
-
-	/* set the mib for hw.ncpu */
-	mib[0] = CTL_HW;
-	mib[1] = HW_AVAILCPU;  // alternatively, try HW_NCPU;
-
-	/* get the number of CPUs from the system */
-	sysctl(mib, 2, &numCPU, &len, NULL, 0);
-
-	if (numCPU < 1)
-	{
-		mib[1] = HW_NCPU;
-		sysctl(mib, 2, &numCPU, &len, NULL, 0);
-		if (numCPU < 1)
-			return 0;
-	}
-
-	return numCPU;
 #else
 	#warning do_getnumcpus is not implemented for your platform yet
 	return 0;
