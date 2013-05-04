--- sj3h/sj.h.orig	2013-05-04 16:36:40.000000000 +0900
+++ sj3h/sj.h	2013-05-04 16:37:11.000000000 +0900
@@ -62,7 +62,11 @@
 #include <sac.h>
 #include <utmpx.h>
 #else
+#if __FreeBSD_version <= 900006
 #include <utmp.h>
+#else
+#include <utmpx.h>
+#endif
 #endif
 #if defined(__sony_news) && defined(SVR4)
 #include <jctype.h>
