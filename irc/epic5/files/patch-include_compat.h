--- include/compat.h.orig	Thu Oct 13 02:49:44 2005
+++ include/compat.h	Fri Sep 29 00:22:25 2006
@@ -62,6 +62,9 @@
 
 #define HN_GETSCALE             0x10
 #define HN_AUTOSCALE            0x20
+
+#ifndef __FreeBSD__
 int	humanize_number (char *, size_t, long, const char *, int, int);
+#endif
 
 #endif
