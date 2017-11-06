--- src/AlWinMain.cpp.orig	2007-10-13 11:06:35 UTC
+++ src/AlWinMain.cpp
@@ -161,7 +161,7 @@ void AlWinMain::connectEditor( AlTextEdi
 */
 void AlWinMain::insertDateTime(){
 	QDateTime dt=QDateTime::currentDateTime();
-	if (ui.list_files->currentItem() > 0)
+	if (ui.list_files->currentItem() != NULL)
 	actualTxt->textCursor().insertText(dt.toString(Qt::LocalDate));
 };
 
@@ -719,7 +719,7 @@ void AlWinMain::refresh()
 */
 void AlWinMain::cancella()
 {
-	if (actualTxt > 0 && ui.list_files->currentItem() > 0)
+	if (actualTxt != NULL && ui.list_files->currentItem() != NULL)
 	actualTxt->clear();
 	
 };
@@ -728,7 +728,7 @@ void AlWinMain::cancella()
 */
 void AlWinMain::insertComment()
 {
-	if (actualTxt > 0 && ui.list_files->currentItem() > 0)
+	if (actualTxt != NULL && ui.list_files->currentItem() != NULL)
 	actualTxt->textCursor().insertText(" /*********/ "
 									" /*       */ "		
 								   " /*********/ " );
