--- storage/innobase/include/srv0mon.h.orig	2016-11-27 19:44:54 UTC
+++ storage/innobase/include/srv0mon.h
@@ -34,6 +34,10 @@ Created 12/15/2009	Jimmy Yang
 /* Required for FreeBSD so that INT64_MAX is defined. */
 #define __STDC_LIMIT_MACROS
 #endif /* __STDC_LIMIT_MACROS */
+#ifdef __DragonFly__
+/* The hack above doen't work for dragonfly, stdint.h already imported */
+#include <machine/int_limits.h>
+#endif
 
 #include <stdint.h>
 
