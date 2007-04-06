
$FreeBSD$

--- ksqlanalyzer/kwrite/kwdialog.h.orig
+++ ksqlanalyzer/kwrite/kwdialog.h
@@ -13,6 +13,8 @@
 
 #include "kwview.h"
 
+class QComboBox;
+
 class SearchDialog : public QDialog {
     Q_OBJECT
   public:
