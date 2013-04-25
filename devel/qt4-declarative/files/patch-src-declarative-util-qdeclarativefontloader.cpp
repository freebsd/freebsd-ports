--- src/declarative/util/qdeclarativefontloader.cpp.orig	2013-04-24 09:08:17.000000000 +0800
+++ src/declarative/util/qdeclarativefontloader.cpp	2013-04-24 09:09:13.000000000 +0800
@@ -64,7 +64,7 @@
 Q_OBJECT
 
 public:
-    QDeclarativeFontObject(int _id);
+    QDeclarativeFontObject(int _id = -1);
 
     void download(const QUrl &url, QNetworkAccessManager *manager);
 
@@ -84,7 +84,7 @@
     Q_DISABLE_COPY(QDeclarativeFontObject)
 };
 
-QDeclarativeFontObject::QDeclarativeFontObject(int _id = -1)
+QDeclarativeFontObject::QDeclarativeFontObject(int _id)
     : QObject(0), id(_id), reply(0), redirectCount(0) {}
 
 
