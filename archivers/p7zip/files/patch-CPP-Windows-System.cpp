Index: CPP/Windows/System.cpp
@@ -35,7 +35,7 @@
 		#elif defined (__FreeBSD__)
 		UInt32 GetNumberOfProcessors() {
 		  		int nbcpu = 1;
-			size_t value;
+			int value;
 			size_t len = sizeof(value);
 			if (sysctlbyname("hw.ncpu", &value, &len, NULL, 0) == 0)
 				nbcpu = value;
