--- widget/lessondialog.cpp.orig	2013-10-30 15:20:29.110117000 +0000
+++ widget/lessondialog.cpp
@@ -89,7 +89,7 @@ void LessonDialog::updateContent() {
 			*lessonData = lineLessonContent->toPlainText().split("\n", QString::SkipEmptyParts);
 			// Delete empty lines
 			for (int i = 0; i < lessonData->size(); i++) {
-				if (QString::QString(lessonData->at(i).toLocal8Bit().constData()).simplified() == "") {
+				if (QString(lessonData->at(i).toLocal8Bit().constData()).simplified() == "") {
 					lessonData->removeAt(i);
 				}
 			}
@@ -259,7 +259,7 @@ void LessonDialog::clickSave() {
 	contentList = lineLessonContent->toPlainText().split("\n", QString::SkipEmptyParts);
 	// Delete empty lines
 	for (i = 0; i < contentList.size(); i++) {
-		if (QString::QString(contentList.at(i).toLocal8Bit().constData()).simplified() == "") {
+		if (QString(contentList.at(i).toLocal8Bit().constData()).simplified() == "") {
 			contentList.removeAt(i);
 		}
 	}
