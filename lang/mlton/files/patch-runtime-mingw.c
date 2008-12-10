--- runtime/platform/mingw.c.orig	2008-04-27 11:10:10.000000000 +1000
+++ runtime/platform/mingw.c	2008-04-27 11:10:33.000000000 +1000
@@ -54,40 +54,6 @@
 }
 
 /* ------------------------------------------------- */
-/*                       Date                        */
-/* ------------------------------------------------- */
-
-#ifndef __GNUC__
-#define EPOCHFILETIME (116444736000000000i64)
-#else
-#define EPOCHFILETIME (116444736000000000LL)
-#endif
-
-/* Based on notes by Wu Yongwei: 
- *   http://mywebpage.netscape.com/yongweiwutime.htm 
- */
-int gettimeofday (struct timeval *tv, struct timezone *tz) {
-        FILETIME ft;
-        LARGE_INTEGER li;
-        __int64 t;
-        static bool tzInit = FALSE;
-
-        unless (tzInit) {
-                tzInit = TRUE;
-                _tzset();
-        }
-        GetSystemTimeAsFileTime (&ft);
-        li.LowPart = ft.dwLowDateTime;
-        li.HighPart = ft.dwHighDateTime;
-        t = li.QuadPart;
-        t -= EPOCHFILETIME;
-        t /= 10;
-        tv->tv_sec = (long)(t / 1000000);
-        tv->tv_usec = (long)(t % 1000000);
-        return 0;
-}
-
-/* ------------------------------------------------- */
 /*                   MLton.Itimer                    */
 /* ------------------------------------------------- */
 
