--- ./kid3/musicbrainzclient.cpp.orig	Tue Jun  6 00:18:36 2006
+++ ./kid3/musicbrainzclient.cpp	Sat Sep 23 01:27:55 2006
@@ -17,10 +17,161 @@
 #define I18N_NOOP(s) QT_TR_NOOP(s)
 #endif
 #include <qfile.h>
+#if HAVE_TUNEPIMP >= 5
+#include <qsocket.h>
+#include <qdom.h>
+#endif
 #include "musicbrainzconfig.h"
 #include "freedbclient.h"
 #include "importtrackdata.h"
 
+#if HAVE_TUNEPIMP >= 5
+/**
+ * Constructor.
+ *
+ * @param numFiles   number of files to be queried
+ * @param serverName server name
+ * @param serverPort server port
+ * @param proxyName  proxy name, empty if no proxy
+ * @param proxyPort  proxy port
+ */
+LookupQuery::LookupQuery(int numFiles,
+												 const QString& serverName, Q_UINT16 serverPort,
+												 const QString& proxyName, Q_UINT16 proxyPort) :
+	m_numFiles(numFiles), m_serverName(serverName), m_serverPort(serverPort),
+	m_proxyName(proxyName), m_proxyPort(proxyPort),
+	m_currentFile(-1), m_fileQueries(new FileQuery[numFiles]),
+	m_sock(new QSocket)
+{
+	for (int i = 0; i < m_numFiles; ++i) {
+		m_fileQueries[i].requested = false;
+		m_fileQueries[i].puid = "";
+	}
+	connect(m_sock, SIGNAL(connected()),
+			this, SLOT(socketConnected()));
+	connect(m_sock, SIGNAL(error(int)),
+			this, SLOT(socketError()));
+	connect(m_sock, SIGNAL(connectionClosed()),
+			this, SLOT(socketConnectionClosed()));
+}
+
+/**
+ * Destructor.
+ */
+LookupQuery::~LookupQuery()
+{
+	m_sock->close();
+	m_sock->disconnect();
+	delete m_sock;
+	delete [] m_fileQueries;
+}
+
+/**
+ * Connect to server to query information about the current file.
+ */
+void LookupQuery::socketQuery()
+{
+	if (m_currentFile >= 0 && m_currentFile < m_numFiles) {
+		QString  destName = m_proxyName.isEmpty() ? m_serverName : m_proxyName;
+		Q_UINT16 destPort = m_proxyName.isEmpty() ? m_serverPort : m_proxyPort;
+		m_request = "GET http://";
+		m_request += m_serverName;
+		if (m_serverPort != 80) {
+			m_request += ':';
+			m_request += QString::number(m_serverPort);
+		}
+		m_request += "/ws/1/track/?type=xml&puid=";
+		m_request += m_fileQueries[m_currentFile].puid;
+		m_request += " HTTP/1.0\r\nHost: ";
+		m_request += m_serverName;
+		m_request += "\r\nUser-agent: Kid3/" VERSION "\r\n\r\n";
+		m_sock->connectToHost(destName, destPort);
+		m_fileQueries[m_currentFile].requested = true;
+	}
+}
+
+/**
+ * Query the next file.
+ */
+void LookupQuery::queryNext()
+{
+	// handle the first pending query
+	for (int i = 0; i < m_numFiles; ++i) {
+		if (!m_fileQueries[i].requested &&
+				!m_fileQueries[i].puid.isEmpty()) {
+			m_currentFile = i;
+			socketQuery();
+			return;
+		}
+	}
+	// no pending query => socketQuery() will be done in next query()
+	m_currentFile = -1;
+}
+
+/**
+ * Query a PUID from the server.
+ *
+ * @param puid  PUID
+ * @param index index of file
+ */
+void LookupQuery::query(const char* puid, int index)
+{
+	m_fileQueries[index].puid = QString(puid);
+	// if no request is being executed, start the current request
+	if (m_currentFile < 0 || m_currentFile >= m_numFiles ||
+			!m_fileQueries[m_currentFile].requested) {
+		m_currentFile = index;
+		socketQuery();
+	}
+}
+
+/**
+ * Send query when the socket is connected.
+ */
+void LookupQuery::socketConnected()
+{
+	m_sock->writeBlock(m_request.latin1(), m_request.length());
+}
+
+/**
+ * Error on socket connection.
+ */
+void LookupQuery::socketError()
+{
+	queryNext();
+}
+
+/**
+ * Read received data when the server has closed the connection.
+ */
+void LookupQuery::socketConnectionClosed()
+{
+	Q_ULONG len = m_sock->bytesAvailable();
+	QCString buf;
+	buf.resize(len + 1 );
+	m_sock->readBlock(buf.data(), len);
+	m_sock->close();
+
+	int xmlStart = buf.find("<?xml");
+	if (xmlStart >= 0 &&
+			m_currentFile >= 0 && m_currentFile < m_numFiles &&
+			m_fileQueries[m_currentFile].requested) {
+		emit queryResponseReceived(m_currentFile, buf.mid(xmlStart, len - xmlStart));
+	}
+	queryNext();
+}
+
+#else
+
+LookupQuery::LookupQuery(int, const QString&, Q_UINT16, const QString&, Q_UINT16) {}
+LookupQuery::~LookupQuery() {}
+void LookupQuery::socketConnected() {}
+void LookupQuery::socketError() {}
+void LookupQuery::socketConnectionClosed() {}
+
+#endif
+
+
 /**
  * Constructor.
  *
@@ -29,6 +180,9 @@
  */
 MusicBrainzClient::MusicBrainzClient(ImportTrackDataVector& trackDataList) :
 	m_trackDataVector(trackDataList), m_tp(0), m_ids(0), m_numFiles(0)
+#if HAVE_TUNEPIMP >= 5
+	, m_lookupQuery(0)
+#endif
 {
 	m_tp = tp_New("kid3", VERSION);
 #ifdef WIN32
@@ -39,7 +193,11 @@
 #else
 	tp_SetUseUTF8(m_tp, 1);
 #endif
+#if HAVE_TUNEPIMP >= 5
+	tp_SetMusicDNSClientId(m_tp, "a95f5c7cd37fd4bce12dc86d196fb4fe");
+#else
 	tp_SetAutoFileLookup(m_tp, 1);
+#endif
 	tp_SetRenameFiles(m_tp, 0);
 	tp_SetMoveFiles(m_tp, 0);
 	tp_SetWriteID3v1(m_tp, 0);
@@ -110,8 +268,13 @@
     { eUnrecognized,  I18N_NOOP("Unrecognized") },
     { eRecognized,    I18N_NOOP("Recognized") },
     { ePending,       I18N_NOOP("Pending") },
+#if HAVE_TUNEPIMP >= 5
+    { ePUIDLookup,     I18N_NOOP("PUID Lookup") },
+    { ePUIDCollision,  I18N_NOOP("PUID Collision") },
+#else
     { eTRMLookup,     I18N_NOOP("TRM Lookup") },
     { eTRMCollision,  I18N_NOOP("TRM Collision") },
+#endif
     { eFileLookup,    I18N_NOOP("File Lookup") },
     { eUserSelection, I18N_NOOP("User Selection") },
     { eVerified,      I18N_NOOP("Verified") },
@@ -163,7 +326,11 @@
 					track_t track = tp_GetTrack(m_tp, id);
 					if (track) {
 						tr_Lock(track);
+#if HAVE_TUNEPIMP >= 5
+						tr_GetPUID(track, trm, sizeof(trm));
+#else
 						tr_GetTRM(track, trm, sizeof(trm));
+#endif
 						if (trm[0] == '\0') {
 							tr_SetStatus(track, ePending);
 							tp_Wake(m_tp, track);
@@ -189,13 +356,33 @@
 						ImportTrackData trackData;
 						getMetaData(id, trackData);
 						emit metaDataReceived(index, trackData);
-					} else if (statusCode == eTRMCollision ||
-										 statusCode == eUserSelection) {
+					}
+#if HAVE_TUNEPIMP >= 5
+					else if (statusCode == ePUIDLookup ||
+									 statusCode == ePUIDCollision ||
+									 statusCode == eFileLookup) {
+						char puid[255];
+						puid[0] = '\0';
+						track_t track = tp_GetTrack(m_tp, id);
+						if (track) {
+							tr_Lock(track);
+							tr_GetPUID(track, puid, sizeof(puid));
+							tr_Unlock(track);
+							tp_ReleaseTrack(m_tp, track);
+						}
+						if (m_lookupQuery) {
+							m_lookupQuery->query(puid, index);
+						}
+					}
+#else
+					else if (statusCode == eTRMCollision ||
+									 statusCode == eUserSelection) {
 						ImportTrackDataVector trackDataList;
 						if (getResults(id, trackDataList)) {
 							emit resultsReceived(index, trackDataList);
 						}
 					}
+#endif
 				}
 				break;
 			}
@@ -242,6 +429,16 @@
 	m_numFiles = m_trackDataVector.count();
 #endif
 	m_ids = new int[m_numFiles];
+#if HAVE_TUNEPIMP >= 5
+	char serverName[80], proxyName[80];
+	short serverPort, proxyPort;
+	tp_GetServer(m_tp, serverName, sizeof(serverName) - 1, &serverPort);
+	tp_GetProxy(m_tp, proxyName, sizeof(proxyName) - 1, &proxyPort);
+	m_lookupQuery = new LookupQuery(m_numFiles, serverName, serverPort,
+																	proxyName, proxyPort);
+	connect(m_lookupQuery, SIGNAL(queryResponseReceived(int, const QCString&)),
+					this, SLOT(parseLookupResponse(int, const QCString&)));
+#endif
 	int i = 0;
 	for (
 #if QT_VERSION >= 300
@@ -271,6 +468,10 @@
 		}
 		delete [] m_ids;
 		m_ids = 0;
+#if HAVE_TUNEPIMP >= 5
+		delete m_lookupQuery;
+		m_lookupQuery = 0;
+#endif
 		m_numFiles = 0;
 	}
 }
@@ -308,6 +509,68 @@
 	}
 }
 
+#if HAVE_TUNEPIMP >= 5
+
+bool MusicBrainzClient::getResults(int, ImportTrackDataVector&) {
+	return false;
+}
+
+/**
+ * Process server response with lookup data.
+ *
+ * @param index    index of file
+ * @param response response from server
+ */
+void MusicBrainzClient::parseLookupResponse(int index, const QCString& response)
+{
+	ImportTrackDataVector trackDataList;
+	QDomDocument doc;
+	if (doc.setContent(response)) {
+		QDomElement trackList =
+			doc.namedItem("metadata").toElement().namedItem("track-list").toElement();
+
+		for (QDomNode trackNode = trackList.namedItem("track");
+				 !trackNode.isNull();
+				 trackNode = trackNode.nextSibling()) {
+			QDomElement track = trackNode.toElement();
+
+			ImportTrackData trackData;
+			trackData.artist =
+				track.namedItem("artist").toElement().namedItem("name").toElement().text();
+			trackData.title = track.namedItem("title").toElement().text();
+
+			for (QDomNode releaseNode =
+						 track.namedItem("release-list").toElement().namedItem("release");
+					 !releaseNode.isNull();
+					 releaseNode = releaseNode.nextSibling() ) {
+				QDomElement release = releaseNode.toElement();
+
+				trackData.album = release.namedItem("title").toElement().text();
+				trackData.track = -1;
+				QDomNode releaseTrackNode = release.namedItem("track-list");
+				if (!releaseTrackNode.isNull()) {
+					QDomElement releaseTrack = releaseTrackNode.toElement();
+					if (!releaseTrack.attribute("offset").isEmpty())
+						trackData.track = releaseTrack.attribute("offset").toInt() + 1;
+				}
+			}
+			trackDataList.append(trackData);
+		}
+	}
+
+	if (trackDataList.size() > 1) {
+		emit resultsReceived(index, trackDataList);
+		emit statusChanged(index, i18n("User Selection"));
+	} else if (trackDataList.size() == 1) {
+		emit metaDataReceived(index, *trackDataList.begin());
+		emit statusChanged(index, i18n("Recognized"));
+	} else {
+		emit statusChanged(index, i18n("Unrecognized"));
+	}
+}
+
+#else
+
 /**
  * Get results for an ambiguous file.
  *
@@ -387,6 +650,10 @@
 	}
 	return resultsAvailable;
 }
+
+void MusicBrainzClient::parseLookupResponse(int, const QCString&) {}
+
+#endif
 
 #else // HAVE_TUNEPIMP
 
