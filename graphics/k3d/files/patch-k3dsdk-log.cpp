--- k3dsdk/log.cpp.orig	2007-09-05 15:59:08.000000000 -0800
+++ k3dsdk/log.cpp	2007-09-05 15:50:05.000000000 -0800
@@ -378,14 +378,7 @@
 
 #else
 
-	void* array[25];
-	int size = ::backtrace(array, 25);
-	char** symbols = ::backtrace_symbols(array, size);
-
-	for(int i = 0; i != size; ++i)
-		Stream << symbols[i] << "\n";
-
-	free(symbols);
+	Stream << "Backtrace unavailable on FreeBSD\n";
 
 #endif
 
