--- src/metabar_widget.cpp.orig	Sun Apr  3 22:35:03 2005
+++ src/metabar_widget.cpp	Sun Apr  3 22:40:09 2005
@@ -763,7 +763,8 @@
 void MetabarWidget::slotRunDesktopFile(const QString &url)
 {
   KURL::List list;
-  KRun::run(KService(new KDesktopFile(url)), list);
+  KService service(new KDesktopFile(url));
+  KRun::run(service, list);
 }
 
 void MetabarWidget::slotShowMore()
