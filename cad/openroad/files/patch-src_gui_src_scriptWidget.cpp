--- src/gui/src/scriptWidget.cpp.orig	2021-03-09 18:14:44 UTC
+++ src/gui/src/scriptWidget.cpp
@@ -42,6 +42,8 @@
 #include <QTimer>
 #include <QVBoxLayout>
 
+#include <sys/errno.h> // for EINVAL
+
 #include "openroad/OpenRoad.hh"
 #include "spdlog/formatter.h"
 #include "spdlog/sinks/base_sink.h"
