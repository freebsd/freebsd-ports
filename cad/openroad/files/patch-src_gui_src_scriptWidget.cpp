--- src/gui/src/scriptWidget.cpp.orig	2020-09-14 08:51:25 UTC
+++ src/gui/src/scriptWidget.cpp
@@ -41,6 +41,8 @@
 #include <QTimer>
 #include <QVBoxLayout>
 
+#include <sys/errno.h> // for EINVAL
+
 #include "openroad/OpenRoad.hh"
 
 namespace gui {
