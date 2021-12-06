--- config/directoriesconfig.cpp.orig   2020-06-11 15:15:15 UTC
+++ config/directoriesconfig.cpp
@@ -64,7 +64,11 @@ void directoriesConfig::readSettings()
   txStockImagesPath=qSettings.value("txStockImagesPath",QString(getenv("HOME"))+"/qsstv/tx_stock/").toString();
   templatesPath=qSettings.value("templatesPath",QString(getenv("HOME"))+"/qsstv/templates/").toString();
   audioPath=qSettings.value("audioPath",QString(getenv("HOME"))+"/qsstv/audio/").toString();
+#ifdef WITH_DOCS
+  docURL=qSettings.value("docURL","file://%%DOCSDIR%%/manual/index.html").toString();
+#else
   docURL=qSettings.value("docURL","http://users.telenet.be/on4qz/qsstv/manual").toString();
+#endif
   saveTXimages=qSettings.value("saveTXimages",false).toBool();
   qSettings.endGroup();
   setParams();
