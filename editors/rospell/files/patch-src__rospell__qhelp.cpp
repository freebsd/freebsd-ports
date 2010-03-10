--- ./src/rospell/qhelp.cpp.orig	2008-10-05 18:09:39.000000000 +0300
+++ ./src/rospell/qhelp.cpp	2010-03-10 20:21:18.839368229 +0200
@@ -37,14 +37,14 @@
 		QString locale_id = QTextCodec::locale();
 		locale_id.truncate(2);
 		locale_id = locale_id.upper();
-		QString handbook_fname = QString(INSTALL_PLACE) + QString("HANDBOOK-") + locale_id;
+		QString handbook_fname = QString(DOC_INSTALL_PLACE) + QString("HANDBOOK-") + locale_id;
 		if (locale_id == "C")
-			handbook_fname = QString(INSTALL_PLACE) + QString("HANDBOOK");
+			handbook_fname = QString(DOC_INSTALL_PLACE) + QString("HANDBOOK");
 		// read the handbook
 		LOG("try to open %s", (const char *) handbook_fname);
 		char *h = UTILS::read_file_malloc((const char *) handbook_fname);
 		if (h == 0) {
-			handbook_fname = QString(INSTALL_PLACE) + QString("HANDBOOK");
+			handbook_fname = QString(DOC_INSTALL_PLACE) + QString("HANDBOOK");
 			LOG("try to open %s", (const char *) handbook_fname);
 			h = UTILS::read_file_malloc((const char *) handbook_fname);
 			if (h == 0) {
