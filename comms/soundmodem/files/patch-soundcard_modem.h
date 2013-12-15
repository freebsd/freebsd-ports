--- soundcard/modem.h.orig	2003-01-02 13:53:04.000000000 -0500
+++ soundcard/modem.h	2013-12-14 17:32:44.000000000 -0500
@@ -103,7 +103,7 @@
 extern void logprintf(unsigned int level, const char *fmt, ...);
 extern void logerr(unsigned int level, const char *st);
 extern unsigned int log_verblevel;
-extern inline int logcheck(unsigned int vl)
+static inline int logcheck(unsigned int vl)
 {
 	return vl <= log_verblevel;
 }
