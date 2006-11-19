+++ ./kid3/freedbclient.cpp	2006-05-28 15:05:28.000000000 +0200
+++ ./kid3/freedbclient.cpp	2006-10-07 21:32:21.000000000 +0200
@@ -21,6 +21,7 @@
 #include <qregexp.h>
 #include <qsocket.h>
 #include <qstatusbar.h>
+#include <qurl.h>
 #include "freedbconfig.h"
 #include "freedbclient.h"
 
@@ -34,7 +35,8 @@
  *
  * @param sb status bar to display progress information.
  */
-FreedbClient::FreedbClient(QStatusBar *sb) : statusBar(sb)
+FreedbClient::FreedbClient(QStatusBar *sb) :
+ statusBar(sb), m_requestType(RT_None)
 {
 	sock = new QSocket();
 	connect(sock, SIGNAL(hostFound()),
@@ -158,7 +160,39 @@
 	}
 #endif
 	sock->connectToHost(dest, destPort);
-	isAlbumRequest = false;
+	m_requestType = RT_FindFreedbSearch;
+
+	statusBar->message(i18n("Connecting..."));
+}
+
+/**
+ * Find keyword in freedb with "cddb album" command of freedb2.org.
+ *
+ * @param cfg  freedb configuration
+ * @param what string with words to search
+ */
+void FreedbClient::findCddbAlbum(const FreedbConfig *cfg, QString what)
+{
+	QString destNamePort(getProxyOrDest(cfg, cfg->server));
+	QString dest;
+	int destPort;
+	splitNamePort(destNamePort, dest, destPort);
+	what.replace(QRegExp(" +"), " "); // collapse spaces
+	QUrl::encode(what);
+	what.replace("%20", "+"); // replace spaces by '+'
+	request = "GET http://" + cfg->server + cfg->cgiPath +
+		"?cmd=cddb+album+" + what + "&hello=noname+localhost+" +
+		"Kid3+" VERSION "&proto=1 HTTP/1.1\r\nHost: " + cfg->server +
+		"\r\nConnection: close\r\n\r\n";
+#if defined WIN32 && QT_VERSION < 300
+	int err = hostnameToAddress(dest);
+	if (err) {
+		statusBar->message(QString("WinSock error %1").arg(err));
+		return;
+	}
+#endif
+	sock->connectToHost(dest, destPort);
+	m_requestType = RT_FindCddbAlbum;
 
 	statusBar->message(i18n("Connecting..."));
 }
@@ -186,14 +220,23 @@
  */
 void FreedbClient::slotConnectionClosed()
 {
-	rcvStr = "";
-	while (sock->canReadLine()) {
-		rcvStr += sock->readLine();
-	}
-	if (isAlbumRequest) {
-		emit albumFinished(rcvStr);
-	} else {
-		emit findFinished(rcvStr);
+	Q_ULONG len = sock->bytesAvailable();
+	QCString s;
+	s.resize(len + 1);
+	sock->readBlock(s.data(), len);
+	rcvStr = QString::fromUtf8(s.data());
+	switch (m_requestType) {
+		case RT_Album:
+			emit albumFinished(rcvStr);
+			break;
+		case RT_FindFreedbSearch:
+			emit findFinished(rcvStr);
+			break;
+		case RT_FindCddbAlbum:
+			emit findCddbAlbumFinished(rcvStr);
+			break;
+		default:
+			qWarning("Unknown freedb request type");
 	}
 	sock->close();
 	statusBar->message(i18n("Ready."));
@@ -256,6 +299,6 @@
 	}
 #endif
 	sock->connectToHost(dest, destPort);
-	isAlbumRequest = true;
+	m_requestType = RT_Album;
 	statusBar->message(i18n("Connecting..."));
 }
