--- aboutform.cpp.orig	2013-10-15 07:01:22 UTC
+++ aboutform.cpp
@@ -11,7 +11,6 @@
 */
 
 #include "aboutform.hpp"
-#include <poppler-version.h>
 #include <QApplication>
 #include <QHBoxLayout>
 #include <QSettings>
@@ -52,7 +51,7 @@ AboutForm::AboutForm(QWidget *parent) : 
     "</ul>"
     "I also provide training and consultancy in C++, Go, Python&nbsp;2, "
     "Python&nbsp;3, C++/Qt, and PyQt4.").arg(qApp->applicationName())
-            .arg(Version).arg(qVersion()).arg(POPPLER_VERSION));
+            .arg(Version).arg(qVersion()).arg("Qt 5"));
     QTextBrowser *contributorsBrowser = new QTextBrowser;
     contributorsBrowser->setReadOnly(true);
     contributorsBrowser->setHtml(tr("<table>"
