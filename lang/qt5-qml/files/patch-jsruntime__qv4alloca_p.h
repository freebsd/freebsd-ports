--- ./jsruntime/qv4alloca_p.h.orig	2014-02-01 20:38:02.000000000 +0000
+++ ./jsruntime/qv4alloca_p.h	2014-02-24 08:11:34.679454851 +0000
@@ -49,7 +49,7 @@
 #  ifndef __GNUC__
 #    define alloca _alloca
 #  endif
-#else
+#elif !defined(Q_OS_FREEBSD)
 #  include <alloca.h>
 #endif
 
