--- ./expoblending/manager/actionthread.cpp.orig	2012-01-02 19:31:39.000000000 -0500
+++ ./expoblending/manager/actionthread.cpp	2012-05-13 07:52:49.000000000 -0400
@@ -32,6 +32,11 @@
 #define log2f(x) (logf(x)*1.4426950408889634f)
 #endif
 
+#include <sys/param.h>
+#if __FreeBSD_version < 802502 || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2f(x) (logf(x) / logf(2))
+#endif
+
 // Qt includes
 
 #include <QMutex>
