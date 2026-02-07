--- tws.c.orig	2014-09-11 21:54:21 UTC
+++ tws.c
@@ -30,16 +30,15 @@
 #include <sys/types.h>
 #include <time.h>
 #include <stdlib.h>
-#ifdef  SYS5
+#if !defined(__FreeBSD__)
+# ifdef SYS5
 extern int daylight;
 extern long timezone;
-#else /*SYS5*/
-#include <sys/timeb.h>
-#endif /*SYS5*/
+# else /*SYS5*/
+#  include <sys/timeb.h>
+# endif /*SYS5*/
+#endif
 
-extern long time();
-struct tm* localtime();
-
 struct tws *dtwstime()
 {
    long clock = 0;
@@ -59,12 +58,12 @@ struct tws* dlocaltime( long* clock )
 
 struct tws* dlocaltime( long* clock )
 {
-register struct tm* tm;
-#ifndef SYS5
+   register struct tm* tm;
+#if !defined(SYS5) && !defined(__FreeBSD__)
    struct timeb tb;
 #endif /*not SYS5*/
    static struct tws tw;
-   
+
    if ( clock == (long*) 0 )
       return (struct tws*) 0;
    tw.tw_flags = TW_NULL;
@@ -80,13 +79,15 @@ register struct tm* tm;
    tw.tw_yday = tm->tm_yday;
    if ( tm->tm_isdst )
       tw.tw_flags |= TW_DST;
-#ifndef  SYS5
-   ftime( &tb );
-   tw.tw_zone = -tb.timezone;
-#else   /*SYS5*/
+#ifdef __FreeBSD__
+   tw.tw_zone = tm->tm_gmtoff / 60;
+#elif defined(SYS5)
    tzset();
    tw.tw_zone = -( timezone / 60 );
-#endif  /*SYS5*/
+#else /*!SYS5&&!__FreeBSD__*/
+   ftime( &tb );
+   tw.tw_zone = -tb.timezone;
+#endif
    tw.tw_flags &= ~TW_SDAY;
    tw.tw_flags |= TW_SEXP;
    tw.tw_clock = *clock;
