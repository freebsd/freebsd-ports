+++ ./kid3/freedbdialog.cpp	2006-02-23 22:48:14.000000000 +0100
+++ ./kid3/freedbdialog.cpp	2006-10-07 21:31:43.000000000 +0200
@@ -24,6 +24,7 @@
 #include <qlistbox.h>
 #include <qlabel.h>
 #include <qstatusbar.h>
+#include <qregexp.h>
 #include "freedbconfig.h"
 #include "freedbclient.h"
 #include "freedbdialog.h"
@@ -109,6 +110,7 @@
 	if (serverLayout && serverLabel && serverComboBox &&
 		cgiLabel && cgiLineEdit) {
 		static const char *serverList[] = {
+			"freedb2.org:80",
 			"freedb.freedb.org:80",
 			"at.freedb.org:80",
 			"au.freedb.org:80",
@@ -155,6 +157,8 @@
 		client = new FreedbClient(statusBar);
 		connect(client, SIGNAL(findFinished(QString)),
 				this, SLOT(slotFindFinished(QString)));
+		connect(client, SIGNAL(findCddbAlbumFinished(QString)),
+				this, SLOT(slotFindCddbAlbumFinished(QString)));
 		connect(client, SIGNAL(albumFinished(QString)),
 				this, SLOT(slotAlbumFinished(QString)));
 	}
@@ -315,7 +319,8 @@
 {
 	FreedbConfig cfg;
 	getFreedbConfig(&cfg);
-	client->find(&cfg, findLineEdit->currentText());
+//	client->find(&cfg, findLineEdit->currentText());
+	client->findCddbAlbum(&cfg, findLineEdit->currentText());
 }
 
 /**
@@ -364,6 +369,58 @@
 }
 
 /**
+ * Process finished findCddbAlbum request.
+ *
+ * @param searchStr search data received
+ */
+void FreedbDialog::slotFindCddbAlbumFinished(QString searchStr)
+{
+/*
+210 exact matches found
+categ discid dtitle
+(more matches...)
+.
+or
+211 close matches found
+rock 920b810c Catharsis / Imago
+.
+theoretically, but never seen
+200	categ discid dtitle
+*/
+	QRegExp catIdTitleRe("([a-z]+)\\s+([0-9a-f]+)\\s+([^/]+ / .+)");
+	QStringList lines = QStringList::split(QRegExp("[\\r\\n]+"), searchStr);
+	bool inEntries = false;
+	albumListBox->clear();
+	for (QStringList::const_iterator it = lines.begin(); it != lines.end(); ++it) {
+		if (*it == ".") {
+			break;
+		}
+		if (inEntries) {
+			if (catIdTitleRe.exactMatch(*it)) {
+				new AlbumListItem(
+					albumListBox,
+					catIdTitleRe.cap(3),
+					catIdTitleRe.cap(1),
+					catIdTitleRe.cap(2));
+			}
+		} else {
+			if ((*it).startsWith("21") && (*it).find(" match") != -1) {
+				inEntries = true;
+			} else if ((*it).startsWith("200 ")) {
+				if (catIdTitleRe.exactMatch((*it).mid(4))) {
+					new AlbumListItem(
+						albumListBox,
+						catIdTitleRe.cap(3),
+						catIdTitleRe.cap(1),
+						catIdTitleRe.cap(2));
+				}
+			}
+		}
+	}
+	albumListBox->setFocus();
+}
+
+/**
  * Process finished album data.
  *
  * @param albumStr album track data received
