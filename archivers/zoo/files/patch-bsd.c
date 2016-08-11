--- bsd.c.orig	1993-05-01 04:21:53 UTC
+++ bsd.c
@@ -69,8 +69,12 @@ ZOOFILE f;
 }
 
 /* Function gettz() returns the offset from GMT in seconds */
-long gettz()
+long gettz(t)
+long t;
 {
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+   return -localtime(&t)->tm_gmtoff;
+#else
 #define SEC_IN_DAY	(24L * 60L * 60L)
 #define INV_VALUE		(SEC_IN_DAY + 1L)
 	static long retval = INV_VALUE;	     /* cache, init to impossible value */
@@ -95,6 +99,7 @@ long gettz()
 	retval = -tm->tm_gmtoff;
 #endif
 	return retval;
+#endif
 }
 
 /* Standard UNIX-compatible time routines */
@@ -103,15 +108,19 @@ long gettz()
 /* Standard UNIX-specific file attribute routines */
 #include "nixmode.i"
 
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#include <unistd.h>
+#else
 #ifndef SEEK_CUR
 # define  SEEK_CUR    1
 #endif
+#endif
 
 /* Truncate a file. */
 int zootrunc(f) FILE *f;
 {
-	extern long lseek();
-	long seekpos;
+	extern off_t lseek();
+	off_t seekpos;
 	int fd = fileno(f);
 	seekpos = lseek(fd, 0L, SEEK_CUR);
 	if (seekpos >= 0)
