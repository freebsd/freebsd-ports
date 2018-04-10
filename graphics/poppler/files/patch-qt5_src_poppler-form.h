--- qt5/src/poppler-form.h.orig	2017-07-02 21:00:50 UTC
+++ qt5/src/poppler-form.h
@@ -26,6 +26,7 @@
 #include <QtCore/QStringList>
 #include <QtCore/QSharedPointer>
 #include "poppler-export.h"
+#include <ctime> // time_t
 
 class Page;
 class FormWidget;
