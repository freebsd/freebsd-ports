--- src/include/configuration.h.orig	2009-01-17 14:58:24.000000000 -0500
+++ src/include/configuration.h	2009-01-17 14:59:32.000000000 -0500
@@ -12,6 +12,10 @@
 #  define DEFAULT_PTTDEV "/dev/ttyS0"
 #  define DEFAULT_CWFSKPORT "/dev/ttyS1"
 #  define DEFAULT_HAMRIGDEVICE "/dev/ttyS0"
+#elif defined(__FreeBSD__)
+#  define DEFAULT_PTTDEV "/dev/ttyd0"
+#  define DEFAULT_CWFSKPORT "/dev/ttyd1"
+#  define DEFAULT_HAMRIGDEVICE "/dev/ttyd0"
 #elif defined(__CYGWIN__)
 #  define DEFAULT_PTTDEV "COM1"
 #  define DEFAULT_CWFSKPORT "COM2"
