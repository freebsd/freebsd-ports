--- ./kid3/genres.h.orig	Thu Jan  5 21:15:20 2006
+++ ./kid3/genres.h	Sat Sep 23 01:28:25 2006
@@ -46,7 +46,7 @@
 	 *
 	 * @return genre number, 255 for unknown index.
 	 */
-	static int getNumber(QString &str);
+	static int getNumber(const QString &str);
 	/** Number of genres */
 #if defined _WIN32 || defined WIN32
 	enum { count = 148 };
