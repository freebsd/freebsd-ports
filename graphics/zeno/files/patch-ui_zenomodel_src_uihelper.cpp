--- ui/zenomodel/src/uihelper.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenomodel/src/uihelper.cpp
@@ -357,16 +357,12 @@ uint UiHelper::generateUuidInt()
 
 bool UiHelper::parseVecType(const QString& type, int& dim, bool& bFloat)
 {
-    static QRegExp rx("vec(2|3|4)(i|f)?");
-    bool ret = rx.exactMatch(type);
-    if (!ret) return false;
-
-    rx.indexIn(type);
-    QStringList list = rx.capturedTexts();
-    if (list.length() == 3)
+    static const QRegularExpression rx(QRegularExpression::anchoredPattern("vec(2|3|4)(i|f)?"));
+    QRegularExpressionMatch match = rx.match(type);
+    if (match.hasMatch())
     {
-        dim = list[1].toInt();
-        bFloat = list[2] != 'i';
+        dim = match.captured(1).toInt();
+        bFloat = match.captured(2) != "i";
         return true;
     }
     else
@@ -1003,10 +999,11 @@ int UiHelper::getMaxObjId(const QList<QS
     int maxObjId = -1;
     for (QString key : lst)
     {
-        QRegExp rx("obj(\\d+)");
-        if (rx.indexIn(key) != -1)
+        static const QRegularExpression rx("obj(\\d+)");
+        QRegularExpressionMatch match = rx.match(key);
+        if (match.hasMatch())
         {
-            auto caps = rx.capturedTexts();
+            auto caps = match.capturedTexts();
             if (caps.length() == 2) {
                 int id = caps[1].toInt();
                 maxObjId = qMax(maxObjId, id);
@@ -1129,14 +1126,15 @@ QVector<qreal> UiHelper::getSlideStep(co
 
 QString UiHelper::nthSerialNumName(QString name)
 {
-    QRegExp rx("\\((\\d+)\\)");
-    int idx = rx.lastIndexIn(name);
+    static const QRegularExpression rx("\\((\\d+)\\)");
+    QRegularExpressionMatch match;
+    int idx = name.lastIndexOf(rx, &match);
     if (idx == -1) {
         return name + "(1)";
     }
     else {
         name = name.mid(0, idx);
-        QStringList lst = rx.capturedTexts();
+        QStringList lst = match.capturedTexts();
         ZASSERT_EXIT(lst.size() == 2, "");
         bool bConvert = false;
         int ith = lst[1].toInt(&bConvert);
