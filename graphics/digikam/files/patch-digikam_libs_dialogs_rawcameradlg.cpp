--- digikam/libs/dialogs/rawcameradlg.cpp.orig	2008-07-16 21:05:55.000000000 +0200
+++ digikam/libs/dialogs/rawcameradlg.cpp	2008-10-12 15:18:00.000000000 +0200
@@ -40,7 +40,6 @@
 // LibKDcraw includes.
 
 #include <libkdcraw/kdcraw.h>
-#include <libkdcraw/dcrawbinary.h>
 
 // Local includes.
 
@@ -77,8 +76,8 @@
     QWidget *page     = makeMainWidget();
     QGridLayout* grid = new QGridLayout(page, 2, 2, 0, spacingHint());
 
-    QStringList list      = KDcrawIface::DcrawBinary::instance()->supportedCamera();
-    QString     dcrawVer  = KDcrawIface::DcrawBinary::instance()->internalVersion();
+    QStringList list      = KDcrawIface::KDcraw::supportedCamera();
+    QString     dcrawVer  = KDcrawIface::KDcraw::librawVersion();
     QString     KDcrawVer = KDcrawIface::KDcraw::version();
 
     // --------------------------------------------------------
@@ -95,7 +94,7 @@
 
     QLabel *header = new QLabel(page);
     header->setText(i18n("<p>Using KDcraw library version %1"
-                         "<p>Using Dcraw program version %2"
+                         "<p>Using LibRaw library version %2"
                          "<p>%3 models in the list")
                          .arg(KDcrawVer).arg(dcrawVer).arg(list.count()));
 
