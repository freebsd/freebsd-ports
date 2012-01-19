--- ./kmymoney/converter/mymoneygncreader.cpp.orig	2011-11-05 05:20:14.000000000 -0400
+++ ./kmymoney/converter/mymoneygncreader.cpp	2012-01-17 04:21:49.000000000 -0500
@@ -1256,7 +1256,6 @@
 #ifndef _GNCFILEANON
 void MyMoneyGncReader::readFile(QIODevice* pDevice, IMyMoneySerialize* storage)
 {
-
   Q_CHECK_PTR(pDevice);
   Q_CHECK_PTR(storage);
 
@@ -1270,6 +1269,8 @@
   MyMoneyFile::instance()->attachStorage(m_storage);
   MyMoneyFileTransaction ft;
   m_xr = new XmlReader(this);
+  bool blocked = MyMoneyFile::instance()->signalsBlocked();
+  MyMoneyFile::instance()->blockSignals(true);
   try {
     m_xr->processFile(pDevice);
     terminate();  // do all the wind-up things
@@ -1278,11 +1279,11 @@
     KMessageBox::error(0, i18n("Import failed:\n\n%1", e->what()), PACKAGE);
     qWarning("%s", qPrintable(e->what()));
   } // end catch
+  MyMoneyFile::instance()->blockSignals(blocked);
   MyMoneyFile::instance()->detachStorage(m_storage);
   signalProgress(0, 1, i18n("Import complete"));  // switch off progress bar
   delete m_xr;
   qDebug("Exiting gnucash importer");
-  return;
 }
 #else
 // Control code for the file anonymizer