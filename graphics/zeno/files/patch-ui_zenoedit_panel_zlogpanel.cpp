--- ui/zenoedit/panel/zlogpanel.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/panel/zlogpanel.cpp
@@ -149,12 +149,13 @@ void LogItemDelegate::initTextLayout(
 QVector<QTextLayout::FormatRange> LogItemDelegate::_getNodeIdentRgs(const QString& content) const
 {
     QVector<QTextLayout::FormatRange> selections;
-    QRegExp rx("[0-9a-z]+\\-[^/\\s`'\"\\],:]+");
+    static const QRegularExpression rx("[0-9a-z]+\\-[^/\\s`'\"\\],:]+");
+    QRegularExpressionMatch match;
     QString currText = content;
 
     int index = -1;
-    while ((index = rx.indexIn(currText, index + 1)) >= 0) {
-        int capLen = rx.cap(0).length();
+    while ((index = currText.indexOf(rx, index + 1, &match)) >= 0) {
+        int capLen = match.capturedLength(0);
         QString strIdent = currText.mid(index, capLen);
 
         QTextLayout::FormatRange frg;
