--- ./kid3/musicbrainzclient.h.orig	Thu Feb 23 22:48:34 2006
+++ ./kid3/musicbrainzclient.h	Sat Sep 23 01:27:55 2006
@@ -15,7 +15,13 @@
 #include <qobject.h>
 
 #ifdef HAVE_TUNEPIMP
+#if HAVE_TUNEPIMP >= 5
+#include <qbuffer.h>
+#include <tunepimp-0.5/tp_c.h>
+class QSocket;
+#else
 #include <tunepimp/tp_c.h>
+#endif
 #endif // HAVE_TUNEPIMP
 
 class MusicBrainzConfig;
@@ -23,6 +29,103 @@
 class ImportTrackDataVector;
 
 /**
+ * A HTTP query to a musicbrainz server for HAVE_TUNEPIMP >= 5.
+ */
+class LookupQuery : public QObject {
+Q_OBJECT
+
+public:
+	/**
+	 * Constructor.
+	 *
+	 * @param numFiles   number of files to be queried
+	 * @param serverName server name
+	 * @param serverPort server port
+	 * @param proxyName  proxy name, empty if no proxy
+	 * @param proxyPort  proxy port
+	 */
+	LookupQuery(int numFiles,
+							const QString& serverName, Q_UINT16 serverPort = 80,
+							const QString& proxyName = "", Q_UINT16 proxyPort = 80);
+
+	/**
+	 * Destructor.
+	 */
+	virtual ~LookupQuery();
+
+#if HAVE_TUNEPIMP >= 5
+	/**
+	 * Query a PUID from the server.
+	 *
+	 * @param puid     PUID
+	 * @param index    index of file
+	 */
+	void query(const char* puid, int index);
+#endif
+
+signals:
+	/**
+	 * Emitted when the query response is received
+	 */
+	void queryResponseReceived(int, const QCString&);
+
+private slots:
+	/**
+	 * Send query when the socket is connected.
+	 */
+	void socketConnected();
+
+	/**
+	 * Error on socket connection.
+	 */
+	void socketError();
+
+	/**
+	 * Read received data when the server has closed the connection.
+	 */
+	void socketConnectionClosed();
+
+#if HAVE_TUNEPIMP >= 5
+private:
+	/**
+	 * Connect to server to query information about the current file.
+	 */
+	void socketQuery();
+
+	/**
+	 * Query the next file.
+	 */
+	void queryNext();
+
+	struct FileQuery {
+		bool requested;
+		QString puid;
+	};
+
+	/** Number of files to be queried. */
+	int m_numFiles;
+	/** MusicBrainz server */
+	QString m_serverName;
+	/** Port of MusicBrainz server */
+	Q_UINT16 m_serverPort;
+	/** Proxy */
+	QString m_proxyName;
+	/** Port of proxy */
+	Q_UINT16 m_proxyPort;
+	/**
+	 * -1 if not yet started,
+	 * 0..m_numFiles-1 if a file is currently processed,
+	 * >=m_numFiles if all files processed.
+	 */ 
+	int m_currentFile;
+	FileQuery* m_fileQueries;
+	QSocket* m_sock;
+	QString m_request;
+#endif
+};
+
+
+/**
  * MusicBrainz client.
  */
 class MusicBrainzClient : public QObject
@@ -85,6 +188,15 @@
 	 */
 	void resultsReceived(int, ImportTrackDataVector&);
 
+private slots:
+	/**
+	 * Process server response with lookup data.
+	 *
+	 * @param index    index of file
+	 * @param response response from server
+	 */
+	void parseLookupResponse(int index, const QCString& response);
+
 #ifdef HAVE_TUNEPIMP
 private:
 	/**
@@ -126,6 +238,9 @@
 	tunepimp_t m_tp;
 	int* m_ids;
 	int m_numFiles;
+#if HAVE_TUNEPIMP >= 5
+	LookupQuery* m_lookupQuery;
+#endif
 #endif // HAVE_TUNEPIMP
 };
 
