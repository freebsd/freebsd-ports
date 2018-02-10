--- blogilo/src/blogger.h.orig	2014-09-11 21:23:20 UTC
+++ blogilo/src/blogger.h
@@ -93,7 +93,7 @@
                       signal emitted after previous authenticate() call.
       @see authenticated(QMap\<QString,QString\>)
     */
-    void authenticate(const QMap<QString, QString> &authData = QMap<QString, QString>());
+    void authenticate(const QMap<QString, QString> &authData = (QMap<QString, QString>()));
 
     /**
       Sets Google OAuth application API key.
