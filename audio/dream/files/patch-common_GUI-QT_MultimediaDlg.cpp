--- common/GUI-QT/MultimediaDlg.cpp.orig	Wed Sep  6 18:57:47 2006
+++ common/GUI-QT/MultimediaDlg.cpp	Wed Sep  6 18:56:33 2006
@@ -34,6 +34,9 @@
 
 #include "MultimediaDlg.h"
 
+int WEXITSTATUS(int ret) {
+    return ret;
+}
 
 /* Implementation *************************************************************/
 MultimediaDlg::MultimediaDlg(CDRMReceiver* pNDRMR, QWidget* parent,
