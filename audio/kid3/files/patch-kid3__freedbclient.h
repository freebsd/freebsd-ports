+++ ./kid3/freedbclient.h	2006-01-05 19:15:21.000000000 +0100
+++ ./kid3/freedbclient.h	2006-10-07 16:06:53.000000000 +0200
@@ -44,6 +44,13 @@
 	 */
 	void find(const FreedbConfig *cfg, QString what);
 	/**
+	 * Find keyword in freedb with "cddb album" command of freedb2.org.
+	 *
+	 * @param cfg  freedb configuration
+	 * @param what string with words to search
+	 */
+	void findCddbAlbum(const FreedbConfig *cfg, QString what);
+	/**
 	 * Request track list from freedb server.
 	 *
 	 * @param cfg freedb configuration
@@ -92,6 +99,11 @@
 	 */
 	void findFinished(QString);
 	/**
+	 * Emitted when findCddbAlbum request finished.
+	 * Parameter: text containing result of findCddbAlbum request
+	 */
+	void findCddbAlbumFinished(QString);
+	/**
 	 * Emitted when album track data request finished.
 	 * Parameter: text containing result of album request
 	 */
@@ -105,8 +117,13 @@
 	QString request;
 	/** buffer for received data */
 	QString rcvStr;
-	/** true if last request was album track data request */
-	bool isAlbumRequest;
+	/** type of current request */
+	enum RequestType {
+		RT_None,
+		RT_FindFreedbSearch,
+		RT_FindCddbAlbum,
+		RT_Album
+	} m_requestType;
 };
 
 #endif
