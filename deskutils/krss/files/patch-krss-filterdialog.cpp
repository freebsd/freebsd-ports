--- krss/filterdialog.cpp.orig	Wed Oct 17 04:05:58 2001
+++ krss/filterdialog.cpp	Wed May 21 10:24:47 2003
@@ -18,6 +18,7 @@
 #include "filterdialog.h"
 
 #include <qradiobutton.h>
+#include <qpushbutton.h>
 
 #include <klocale.h>
 #include <klistview.h>
@@ -27,6 +28,8 @@
 #include "filterviewbackend.h"
 
 #include "filterruledialog.h"
+
+using namespace std;
 
 
 FilterDialog::FilterDialog(QWidget *parent, const char *name )
