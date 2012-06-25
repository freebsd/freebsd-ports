--- ../svxlink-11.05.orig/qtel/qtel.cpp	2009-07-19 15:51:16.000000000 -0700
+++ qtel/qtel.cpp	2012-05-28 10:27:56.000000000 -0700
@@ -141,7 +141,7 @@
   
   QTranslator translator(0);
   translator.load(QString("qtel_") + QTextCodec::locale(),
-      "/usr/share/qtel/translations");
+      "%%LOCALBASE%%/share/qtel/translations");
   app.installTranslator(&translator);
 	
   Settings *settings = Settings::instance();
