--- pathnames.h.orig	2020-10-18 03:01:26 UTC
+++ pathnames.h
@@ -29,9 +29,12 @@
  * SUCH DAMAGE.
  *
  *	@(#)pathnames.h	8.1 (Berkeley) 6/6/93
- * $FreeBSD$
+ * $FreeBSD: head/usr.bin/calendar/pathnames.h 366962 2020-10-23 09:22:23Z se $
  */
 
 #include <paths.h>
 
+#define s1(s)	#s
+#define s2(s)	s1(s)
 #define	_PATH_INCLUDE	"/usr/share/calendar"
+#define	_PATH_INCLUDE_LOCAL	s2(LOCALBASE) "/share/calendar"
