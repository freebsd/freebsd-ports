--- include/mitsuba/core/platform.h.orig	2015-07-15 10:37:38 UTC
+++ include/mitsuba/core/platform.h
@@ -70,6 +70,11 @@
 	#if !defined(_GNU_SOURCE)
 		#define _GNU_SOURCE
 	#endif
+#elif defined(__FreeBSD__)
+	// Try to masquerade as Linux by default (to reduce the amount of
+	// patching); when linuxisms won't work, we'd check for __FreeBSD__
+	// explicitly first.
+	#define __LINUX__
 #else
 	#error Unknown OS
 #endif
