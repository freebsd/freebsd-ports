--- src/plugins/android/androiddevice.cpp.orig	2016-06-21 13:37:35 UTC
+++ src/plugins/android/androiddevice.cpp
@@ -27,6 +27,8 @@
 #include "androidconstants.h"
 #include "androidsignaloperation.h"
 
+#include <projectexplorer/runnables.h>
+
 #include <QCoreApplication>
 
 using namespace ProjectExplorer;
