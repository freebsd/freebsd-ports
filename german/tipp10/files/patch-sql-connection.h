--- ./sql/connection.h.orig	2007-10-02 20:22:22.000000000 +0800
+++ ./sql/connection.h	2008-08-24 16:25:30.000000000 +0800
@@ -170,6 +170,7 @@
 				// -> copy database to user home dir
 				QFile file(QCoreApplication::applicationDirPath() + "/" + dbNameTemplate);
 				if (file.copy(dbPath)) {
+ 					QFile::setPermissions(dbPath, QFile::permissions(dbPath) | QFile::WriteUser);
 					dbExist = true;
 				} else {
 					ErrorMessage *errorMessage = new ErrorMessage();
@@ -201,6 +202,7 @@
 				dir.cd("tipp10");
 				QFile file(dbPath);
 				if (file.copy(dir.path() + "/" + dbNameUser)) {
+ 					QFile::setPermissions(dir.path() + "/" + dbNameUser, QFile::permissions(dir.path() + "/" + dbNameUser) | QFile::WriteUser);
 					dbPath = dir.path() + "/" + dbNameUser;
 				} else {
 					ErrorMessage *errorMessage = new ErrorMessage();
