--- ImageLounge/3rdparty/drif/drif_image.h.orig	2020-03-25 14:20:37 UTC
+++ ImageLounge/3rdparty/drif/drif_image.h
@@ -26,7 +26,7 @@
 #include <stdint.h>
 #include <stdio.h>
 
-#if defined(Q_OS_MAC) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_MAC) || defined(Q_OS_OPENBSD) || defined(Q_OS_FREEBSD)
 #include <stdlib.h>
 #else 
 #include <malloc.h>
