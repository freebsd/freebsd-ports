--- dtime.c.orig	1991-09-14 05:15:25 UTC
+++ dtime.c
@@ -26,13 +26,20 @@ extern long timezone;
 #include <sys/timeb.h>
 #endif /*SYS5*/
 
+
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if !(defined(BSD) && (BSD >= 199306))
 extern long time();
 struct tm* localtime();
+#endif
 
 struct tws*
 dtwstime()
     {
-    long clock;
+    time_t clock;
 
     (void) time( &clock );
     return dlocaltime( &clock );
@@ -40,7 +47,7 @@ dtwstime()
 
 struct tws*
 dlocaltime( clock )
-    long* clock;
+    time_t* clock;
     {
     register struct tm* tm;
 #ifndef SYS5
@@ -48,7 +55,7 @@ dlocaltime( clock )
 #endif not SYS5
     static struct tws tw;
 
-    if ( clock == (long*) 0 )
+    if ( clock == (time_t*) 0 )
 	return (struct tws*) 0;
     tw.tw_flags = TW_NULL;
 
