--- CPP/Windows/System.cpp.orig	2015-11-20 21:33:04 UTC
+++ CPP/Windows/System.cpp
@@ -44,7 +44,7 @@ namespace NWindows
 		#elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
 		UInt32 GetNumberOfProcessors() {
 		  	int nbcpu = 1;
-			size_t value;
+			int value;
 			size_t len = sizeof(value);
 			if (sysctlbyname("hw.ncpu", &value, &len, NULL, 0) == 0)
 				nbcpu = value;
