--- src/Patchage.cpp.orig	2011-01-09 22:53:06 UTC
+++ src/Patchage.cpp
@@ -21,6 +21,11 @@
 #include <fstream>
 #include <sstream>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2f(x) (logf(x) / logf(2))
+#endif
+
 #include <gtk/gtkwindow.h>
 #include <libglademm/xml.h>
 #include <libgnomecanvasmm.h>
