--- krss/krss.cpp~	Wed Feb 20 09:00:22 2002
+++ krss/krss.cpp	Tue Sep 10 23:11:14 2002
@@ -24,6 +24,7 @@
 #include <qscrollbar.h>
 #include <qsplitter.h>
 #include <qlayout.h>
+#include <qregexp.h>
 
 // include files for KDE
 #include <kiconloader.h>
@@ -46,7 +47,7 @@
 #include <kwinmodule.h>
 #include <khtml_part.h>
 #include <khtmlview.h>
-
+#include <kstatusbar.h>
 
 // application specific includes
 #include "krss.h"
@@ -518,7 +519,7 @@
 {
 	config->setGroup(QString("General"));
 	QString mExec = config->readEntry(QString("Open URLs With"), QString("konqueror %url"));
-	mExec.replace(QString("%url"), url.url());
+	mExec.replace(QRegExp("%url"), url.url());
 		
 	slotStatusMsg(i18n("Starting ") + mExec + QString("..."));
 	
@@ -967,12 +968,12 @@
 		config->setGroup(QString("General"));
 		QStringList uh_list = config->readListEntry(QString("URL Handlers"));
 		QString default_handler = config->readEntry(QString("Open URLs With"), QString("konqueror %url"));
-		default_handler.replace(QString("%url"), url);
+		default_handler.replace(QRegExp("%url"), url);
 		menu.insertItem(default_handler);
 		menu.insertSeparator();
 		for(QStringList::Iterator i = uh_list.begin(); i != uh_list.end(); i++) {
 			QString handler((*i).latin1());
-			handler.replace(QString("%url"), url);
+			handler.replace(QRegExp("%url"), url);
 			menu.insertItem(handler);
 		}
 		int ret = menu.exec(p);
