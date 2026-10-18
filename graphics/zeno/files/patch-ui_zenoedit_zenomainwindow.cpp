--- ui/zenoedit/zenomainwindow.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/zenomainwindow.cpp
@@ -1479,7 +1479,7 @@ void ZenoMainWindow::onZenovisFrameUpdat
 
 void ZenoMainWindow::onCheckUpdate()
 {
-#ifdef __linux__
+#if defined( __linux__) || defined(__FreeBSD__)
     return;
 #else
     ZCheckUpdateDlg dlg(this);
@@ -1821,20 +1821,16 @@ void ZenoMainWindow::openFileAndUpdatePa
 
 void ZenoMainWindow::sortRecentFile(QStringList &lst) 
 {
-    qSort(lst.begin(), lst.end(), [](const QString &s1, const QString &s2) {
-        static QRegExp rx("File (\\d+)");
+    std::sort(lst.begin(), lst.end(), [](const QString &s1, const QString &s2) {
+        static const QRegularExpression rx("File (\\d+)");
         int num1 = 0;
-        if (rx.indexIn(s1) != -1) {
-            QStringList caps = rx.capturedTexts();
-            if (caps.length() == 2)
-                num1 = caps[1].toInt();
-        }
+        QRegularExpressionMatch match1 = rx.match(s1);
+        if (match1.hasMatch())
+            num1 = match1.captured(1).toInt();
         int num2 = 0;
-        if (rx.indexIn(s2) != -1) {
-            QStringList caps = rx.capturedTexts();
-            if (caps.length() == 2)
-                num2 = caps[1].toInt();
-        }
+        QRegularExpressionMatch match2 = rx.match(s2);
+        if (match2.hasMatch())
+            num2 = match2.captured(1).toInt();
         return num1 > num2;
     });
 }
@@ -1867,12 +1863,12 @@ void ZenoMainWindow::recordRecentFile(co
         idx = 0;
     } else {
         QString key = keys.first();
-        static QRegExp rx("File (\\d+)");
-        if (rx.indexIn(key) != -1) 
+        static const QRegularExpression rx("File (\\d+)");
+        QRegularExpressionMatch match = rx.match(key);
+        if (match.hasMatch())
         {
-            QStringList caps = rx.capturedTexts();
-            if (caps.length() == 2 && idx < caps[1].toInt())
-                idx = caps[1].toInt();
+            if (idx < match.captured(1).toInt())
+                idx = match.captured(1).toInt();
         }
     }
 
