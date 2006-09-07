--- tests/semaphore_test.cpp.orig	Thu Jul 20 06:30:56 2006
+++ tests/semaphore_test.cpp	Wed Sep  6 16:30:11 2006
@@ -16,6 +16,7 @@
 using namespace std;
 
 #include <assert.h>
+#include <sys/types.h>
 
 #if !defined (WIN32)
 #   include <sys/ipc.h>		// ftok(2)
