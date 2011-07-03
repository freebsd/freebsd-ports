--- ./src/Sync/DownloadOSM.cpp.orig	2011-06-28 02:32:00.000000000 +0200
+++ ./src/Sync/DownloadOSM.cpp	2011-06-28 02:33:10.000000000 +0200
@@ -252,7 +252,7 @@
 
     QString sReq = url.toString(QUrl::RemoveScheme | QUrl::RemoveAuthority);
     QHttpRequestHeader Header(Method,sReq);
-    Header.setValue("Host",url.host()+':'+url.port(80));
+    Header.setValue("Host",url.host()+':'+QString::number(url.port(80)));
     Header.setValue("User-Agent", USER_AGENT);
 
     QString auth = QString("%1:%2").arg(User).arg(Password);
