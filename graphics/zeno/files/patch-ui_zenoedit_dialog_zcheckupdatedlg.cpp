--- ui/zenoedit/dialog/zcheckupdatedlg.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/dialog/zcheckupdatedlg.cpp
@@ -138,10 +138,11 @@ void ZCheckUpdateDlg::getCudaVersion()
     connect(process, &QProcess::readyReadStandardOutput, this, [=] {
         QString output = process->readAllStandardOutput();
         //Cuda compilation tools, release 12.1
-        QRegExp rx("Cuda compilation tools, release (\\d+)\\.(\\d+)");
-        if (rx.indexIn(output) != -1)
+        static const QRegularExpression rx("Cuda compilation tools, release (\\d+)\\.(\\d+)");
+        QRegularExpressionMatch match = rx.match(output);
+        if (match.hasMatch())
         {
-            auto caps = rx.capturedTexts();
+            auto caps = match.capturedTexts();
             int ver;
             if (caps.length() == 3) {
                 ver = caps[1].toInt();
