--- plugins/sf2_player/sf2_player.cpp.orig	2011-07-02 13:14:01.000000000 +0000
+++ plugins/sf2_player/sf2_player.cpp	2011-09-29 12:18:02.000000000 +0000
@@ -23,6 +23,10 @@
  *
  */
 
+#include <math.h>
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+	#define log2(x)             ( log (x) * (1./M_LN2) )
+#endif
 #include <QtCore/QDebug>
 #include <QtCore/QTextStream>
 #include <QtGui/QLayout>
