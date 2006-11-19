+++ ./kid3/freedbdialog.h	2006-02-23 22:39:28.000000000 +0100
+++ ./kid3/freedbdialog.h	2006-10-07 17:19:08.000000000 +0200
@@ -117,6 +117,12 @@
 	 */
 	void slotFindFinished(QString searchStr);
 	/**
+	 * Process finished findCddbAlbum request.
+	 *
+	 * @param searchStr search data received
+	 */
+	void slotFindCddbAlbumFinished(QString searchStr);
+	/**
 	 * Process finished album data.
 	 *
 	 * @param albumStr album track data received
