--- kghostview/kgv_miniwidget.h.orig	Sun Sep 15 23:12:40 2002
+++ kghostview/kgv_miniwidget.h	Mon Apr  7 17:02:48 2003
@@ -85,7 +85,7 @@ protected:
     void clearTemporaryFiles();
     
     void uncompressFile();
-    void openPSFile();
+    void openPSFile(const QString &file=QString::null);
 
 protected slots:
     void doOpenFile();
@@ -116,7 +116,7 @@ protected:
 /*- PRINTING and SAVING ---------------------------------------------------*/
 
 // private data used: 
-//   Document specific: _dsc, _fileName, _pdfFileName, _format, _origurl
+//   Document specific: _dsc, _fileName, _format, _origurl
 //   View specific:     _currentPage, _marklist 
 //   This section only: _printer, _tmpFromPDF
     
@@ -267,7 +267,6 @@ private:
     int _visiblePage;
 
     QString _fileName;
-    QString _pdfFileName;
     QString _mimetype;
 
     MarkList* _marklist;
