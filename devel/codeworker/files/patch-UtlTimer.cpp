--- UtlTimer.cpp.orig	Wed Dec 31 10:07:18 2003
+++ UtlTimer.cpp	Wed Dec 31 10:09:12 2003
@@ -30,6 +30,7 @@
 #	include "windows.h"
 #	include "winbase.h"
 #else
+#	include <time.h>
 #	include <sys/timeb.h>
 #endif
 
