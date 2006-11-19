--- ./kid3/genres.cpp.orig	Thu May 25 19:58:19 2006
+++ ./kid3/genres.cpp	Sat Sep 23 01:28:25 2006
@@ -385,7 +385,7 @@
  * @return genre number, 255 for unknown index.
  */
 
-int Genres::getNumber(QString &str)
+int Genres::getNumber(const QString &str)
 {
 	for (int i = 0; i < Genres::count + 1; i++) {
 		if (QString(genre[i]) == str) {
