--- ./generator/qtscript_masterinclude.h.orig	2012-01-23 03:30:03.000000000 -0800
+++ ./generator/qtscript_masterinclude.h	2012-04-24 04:41:24.458404620 -0700
@@ -53,12 +53,10 @@
 #  include <QtXmlPatterns/QtXmlPatterns>
 #endif
 
-#ifndef QT_NO_WEBKIT
 #  include <QtWebKit/QtWebKit>
-#endif
 
 #ifndef QT_NO_PHONON
-#  include <phonon/phonon>
+#  include <phonon/phononnamespace.h>
 #endif
 
 #include "../qtbindings/qtscript_core/qtscriptconcurrent.h"
