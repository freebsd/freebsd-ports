--- src/tools/qcmsevents/qcmsevents.cpp.orig	2016-12-09 10:36:53 UTC
+++ src/tools/qcmsevents/qcmsevents.cpp
@@ -9,6 +9,11 @@
 
 #include <cstdio>
 
+#include <QAction>
+#include <QActionGroup>
+#include <QVBoxLayout>
+#include <QMenu>
+
 #define TARGET "X Color Management Events"
 #include "qcmsevents.h"
 #include "oyranos.h"
@@ -17,13 +22,6 @@
 #include "oyranos_io.h"
 #include "oyProfile_s.h"
 #include "oyObject_s.h"
-
-#include <X11/Xcm/Xcm.h>
-
-#include <QAction>
-#include <QActionGroup>
-#include <QVBoxLayout>
-#include <QMenu>
 
 QcmseDialog * dialog = NULL;
 
