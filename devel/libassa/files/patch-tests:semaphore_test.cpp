--- tests/semaphore_test.cpp.orig	Thu Jan 29 08:42:17 2004
+++ tests/semaphore_test.cpp	Thu Jan 29 08:42:43 2004
@@ -16,6 +16,7 @@
 using namespace std;
 
 #include <assert.h>
+#include <sys/types.h>
 #include <sys/ipc.h>		// ftok(2)
 
 #include "assa/Assert.h"
