--- ui/zenoedit/viewport/displaywidget.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/viewport/displaywidget.cpp
@@ -141,7 +141,7 @@ void DisplayWidget::resizeViewport(QSize
 {
     if (m_bGLView) {
         m_glView->resizeGL(sz.width(), sz.height());
-        m_glView->updateGL();
+        m_glView->update();
     } else {
         //todo: for optix view
     }
@@ -1026,7 +1026,7 @@ void DisplayWidget::sendTaskToServer(con
     if (!path.startsWith("O:") && !path.startsWith("M:") && !path.startsWith("P:"))
     {
         //copy zsg
-        QString destFileDir = "O:/sendToServer/" + info.taskName + QString::number(QDateTime::currentDateTime().toTime_t());
+        QString destFileDir = "O:/sendToServer/" + info.taskName + QString::number(QDateTime::currentDateTime().toSecsSinceEpoch());
         QFileInfo fileInfo(path);
         QString fileName = fileInfo.fileName();
         QDir dir(destFileDir);
@@ -1208,9 +1208,10 @@ bool DisplayWidget::onRecord_cmd(const V
             QByteArray content = recordcmd->readLine();
             if (content.startsWith("[record]")) {
                 if (content.indexOf("frame") != -1) {
-                    QRegExp rx("frame (\\d+)");
-                    if (rx.indexIn(content) != -1) {
-                        QStringList caps = rx.capturedTexts();
+                    static const QRegularExpression rx("frame (\\d+)");
+                    QRegularExpressionMatch match = rx.match(QString::fromUtf8(content));
+                    if (match.hasMatch()) {
+                        QStringList caps = match.capturedTexts();
                         ZASSERT_EXIT(caps.size() == 2);
                         int frame_ = caps[1].toInt();
                         dlgProc.onFrameFinished(frame_);
