--- dspdfviewer.h.orig	2016-09-13 13:18:47 UTC
+++ dspdfviewer.h
@@ -22,6 +22,7 @@
 #define dspdfviewer_H
 
 #include <QObject>
+#include <QElapsedTimer>
 #include <QTimer>
 #include <QFileSystemWatcher>
 #include "poppler-qt.h"
@@ -42,8 +43,8 @@ class DSPDFViewer: public QObject (private)
 
 private:
   QTimer	clockDisplayTimer;
-  QTime 	slideStart;
-  QTime		presentationStart;
+  QElapsedTimer 	slideStart;
+  QElapsedTimer		presentationStart;
   bool		presentationClockRunning;
 
 private:
@@ -89,7 +90,7 @@ private slots: (public)
     QTime slideClock() const;
     QTime presentationClock() const;
 
-    QTime timeSince( const QTime& startPoint) const;
+    QTime timeSince( const QElapsedTimer& startPoint) const;
 
     bool isAudienceScreenBlank() const;
 
