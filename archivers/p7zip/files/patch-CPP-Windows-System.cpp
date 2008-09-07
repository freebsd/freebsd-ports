--- CPP/Windows/System.cpp.orig	2008-09-07 02:29:34.000000000 +0800
+++ CPP/Windows/System.cpp	2008-09-07 02:30:23.000000000 +0800
@@ -44,7 +44,7 @@
 		#elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
 		UInt32 GetNumberOfProcessors() {
 		  	int nbcpu = 1;
-			size_t value;
+		  	int value;
 			size_t len = sizeof(value);
 			if (sysctlbyname("hw.ncpu", &value, &len, NULL, 0) == 0)
 				nbcpu = value;
