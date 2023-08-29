--- src/main.cpp.orig	2018-06-17 14:02:54 UTC
+++ src/main.cpp
@@ -1,4 +1,4 @@
-#include <sys/timeb.h>
+#include <sys/time.h>
 
 #include <QTranslator>
 #include <QToolButton>
@@ -572,9 +572,9 @@ int getMilliCount(void)
   // Something like GetTickCount but portable
   // It rolls over every ~ 12.1 days (0x100000/24/60/60)
   // Use getMilliSpan to correct for rollover
-  timeb tb;
-  ftime( &tb );
-  int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
+  timeval tv;
+  gettimeofday(&tv, NULL);
+  int nCount = tv.tv_usec / 1000 + (tv.tv_sec & 0xfffff) * 1000;
   return nCount;
 }
 
