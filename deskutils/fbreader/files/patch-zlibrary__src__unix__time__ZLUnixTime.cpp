--- ./zlibrary/src/unix/time/ZLUnixTime.cpp.orig	Tue Apr 17 22:53:30 2007
+++ ./zlibrary/src/unix/time/ZLUnixTime.cpp	Sat Apr 21 19:00:15 2007
@@ -18,15 +18,14 @@
  * 02110-1301, USA.
  */
 
-#include <sys/timeb.h>
-#include <time.h>
+#include <sys/time.h>
 
 #include "ZLUnixTime.h"
 
 ZLTime ZLUnixTimeManager::currentTime() const {
-	struct timeb timeB;
-	ftime(&timeB);
-	return ZLTime(timeB.time, timeB.millitm);
+	struct timeval timeB;
+	gettimeofday(&timeB,NULL);
+	return ZLTime(timeB.tv_sec, timeB.tv_usec/1000);
 }
 
 short ZLUnixTimeManager::hoursBySeconds(long seconds) const {
