--- src/gui/dictionary_tool/dictionary_tool.cc.orig	2026-09-15 04:25:06 UTC
+++ src/gui/dictionary_tool/dictionary_tool.cc
@@ -34,13 +34,13 @@
 #endif  // OS_ANDROID || OS_NACL
 
 #include <QtCore/QTimer>
+#include <QtGui/QShortcut>
 #include <QtGui/QtGui>
 #include <QtWidgets/QProgressDialog>
 #include <QtWidgets/QMessageBox>
 #include <QtWidgets/QFileDialog>
 #include <QtWidgets/QMenu>
 #include <QtWidgets/QInputDialog>
-#include <QtWidgets/QShortcut>
 
 #ifdef OS_WIN
 #include <Windows.h>
@@ -88,7 +88,7 @@ int GetTableHeight(QTableWidget *widget) {
   // Here we use "龍" to calc font size, as it looks almsot square
   const char kHexBaseChar[] = "龍";
   const QRect rect =
-      QFontMetrics(widget->font()).boundingRect(QObject::trUtf8(kHexBaseChar));
+      QFontMetrics(widget->font()).boundingRect(QObject::tr(kHexBaseChar));
   return static_cast<int>(rect.height() * 1.4);
 }
 
@@ -129,7 +129,7 @@ class UTF16TextLineIterator
       LOG(ERROR) << "Cannot open: " << filename;
     }
     stream_->setDevice(&file_);
-    stream_->setCodec("UTF-16");
+    stream_->setEncoding(QStringConverter::Utf16);
     progress_.reset(CreateProgressDialog(message, parent, file_.size()));
   }
 
@@ -168,7 +168,7 @@ class UTF16TextLineIterator
     file_.seek(0);
     stream_.reset(new QTextStream);
     stream_->setDevice(&file_);
-    stream_->setCodec("UTF-16");
+    stream_->setEncoding(QStringConverter::Utf16);
   }
 
  private:
