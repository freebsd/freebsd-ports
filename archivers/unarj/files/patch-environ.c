--- environ.c.orig	2002-06-05 08:28:06 UTC
+++ environ.c
@@ -430,16 +430,24 @@ uint  host;
 
 #define SUBS_DEFINED
 
+#include <stdlib.h>
+#include <string.h>
 #include <time.h>
+#include <sys/types.h>
+#include <utime.h>
 
-#ifndef time_t
-#define time_t long
-#endif
+/*#ifndef time_t
+ #define time_t long
+ #endif*/
+
+#include <sys/param.h>
 
+#if !(defined(BSD) && BSD >= 199306)
 extern struct tm *localtime();
 extern time_t time();
 extern char   *strcpy();
 extern voidp  *malloc();
+#endif
 
 FILE *
 file_open(name, mode)
@@ -535,8 +543,12 @@ uint mode;
 }
 
 long
-gettz()         /* returns the offset from GMT in seconds */
+gettz(stamp)         /* returns the offset from GMT in seconds */
+time_t stamp;
 {
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+	return -localtime(&stamp)->tm_gmtoff;
+#else
 #define NOONOFFSET    43200L
 #define SEC_IN_DAY    (24L * 60L * 60L)
 #define INV_VALUE     (SEC_IN_DAY + 1L)
@@ -552,6 +564,7 @@ gettz()         /* returns the offset fr
     noontm = localtime(&noon);
     retval = NOONOFFSET - 60 * (60 * noontm->tm_hour - noontm->tm_min);
     return retval;
+#endif
 }
 
 long
@@ -600,19 +613,29 @@ uint  host;
 {
     time_t m_time;
     struct utimbuf
+#ifndef __FreeBSD__
     {
        time_t atime;             /* New access time */
        time_t mtime;             /* New modification time */
     } tb;
+#else
+    tb;
+#endif
 
     (char *) name;
     (uint) attribute;
     (uint) host;
 
-    m_time = mstonix(tstamp) + gettz();
+    m_time = mstonix(tstamp);
+    m_time += gettz(m_time);
 
+#ifndef __FreeBSD__
     tb.mtime = m_time;                  /* Set modification time */
     tb.atime = m_time;                  /* Set access time */
+#else
+    tb.modtime = m_time;                /* Set modification time */
+    tb.actime = m_time;                 /* Set access time */
+#endif
 
     /* set the time stamp on the file */
     return utime(name, &tb);
