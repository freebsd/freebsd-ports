--- src/backend/AStatusComm.cpp.orig	Sun May  1 09:53:40 2005
+++ src/backend/AStatusComm.cpp	Mon May 16 21:35:32 2005
@@ -94,12 +94,12 @@
 
 // --- CStatusBar --------------------------------------
 
-#include <sys/timeb.h>
+#include <sys/time.h>
 static unsigned long getCurrentMilliseconds()
 {
-	struct timeb tb;
-	ftime(&tb);
-	return (unsigned long)tb.time*1000UL+(unsigned long)tb.millitm;
+	struct timeval tp;
+	(void)gettimeofday(&tp, NULL);
+	return (unsigned long)tp.tv_sec*1000UL+(unsigned long)tp.tv_usec/1000UL;
 }
 
 CStatusBar::CStatusBar(const string title,const sample_pos_t firstValue,const sample_pos_t lastValue,const bool showCancelButton) :
