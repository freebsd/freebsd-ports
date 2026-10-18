--- ui/zenoui/style/zenostyle.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/style/zenostyle.cpp
@@ -59,11 +59,11 @@ QString ZenoStyle::dpiScaleSheet(const Q
         return tempStyle;
     }
 
-    QRegExp rx("\\d+px", Qt::CaseInsensitive);
-    rx.setMinimal(true);
+    static const QRegularExpression rx("\\d+?px", QRegularExpression::CaseInsensitiveOption);
+    QRegularExpressionMatch match;
     int index = -1;
-    while ((index = rx.indexIn(tempStyle, index + 1)) >= 0) {
-        int capLen = rx.cap(0).length() - 2;
+    while ((index = tempStyle.indexOf(rx, index + 1, &match)) >= 0) {
+        int capLen = match.capturedLength(0) - 2;
         QString strNum = tempStyle.mid(index, capLen);
         strNum = QString::number(qRound(strNum.toInt() * scale));
         tempStyle.replace(index, capLen, strNum);
