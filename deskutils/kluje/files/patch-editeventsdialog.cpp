--- kluje/editeventsdialog.cpp.orig	Wed Jul 17 06:01:24 2002
+++ kluje/editeventsdialog.cpp	Thu Dec 23 10:56:25 2004
@@ -159,7 +159,7 @@
   this->setEnabled(false);
   this->setCursor(QCursor(Qt::WaitCursor));
   subjLineEdit->setCursor(QCursor(Qt::WaitCursor));
-  eventEdit->setCursor(QCursor(Qt::WaitCursor));
+  eventEdit->QMultiLineEdit::setCursor(QCursor(Qt::WaitCursor));
 }
 
 void EditEventsDialog::enable()
@@ -167,7 +167,7 @@
   this->setEnabled(true);
   this->setCursor(QCursor(Qt::ArrowCursor));
   subjLineEdit->setCursor(QCursor(Qt::ArrowCursor));
-  eventEdit->setCursor(QCursor(Qt::ArrowCursor));
+  eventEdit->QMultiLineEdit::setCursor(QCursor(Qt::ArrowCursor));
 }
 
 EditEventsDialog::~EditEventsDialog()
