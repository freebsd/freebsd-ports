--- dbdesign/dbdesign.cpp.orig	Wed Jun 13 22:27:17 2001
+++ dbdesign/dbdesign.cpp	Sat May 18 17:02:04 2002
@@ -270,7 +270,8 @@
 */
 
 int DbDesign::refreshPlugins(){
-	QString path = QString(getenv("KDEDIR")) + "/" + KStandardDirs::kde_default("data") + "/dbdesign/plugins/";
+	QString kdeprefix = QString(KDEDIR);
+	QString path = kdeprefix + "/" + KStandardDirs::kde_default("data") + "/dbdesign/plugins/";
 	QDir pldir(path, "*plug.so", QDir::IgnoreCase | QDir::Name, QDir::Files);
 	bool foundstd = false;
 	void* h;
