mainwindow.cc:351:82: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
        QMessageBox::about(this, "About", QString("<font size=\"+2\">Spellathon </font>"VERSION"&nbsp;&nbsp;<font color=\"gray\">(svn%1)</font><br><br>&copy;"COPYRIGHT"<br>").arg(svn_version()));
                                                                                        ^

--- src/gui/mainwindow.cc.orig	2018-08-02 06:22:41 UTC
+++ src/gui/mainwindow.cc
@@ -348,7 +348,7 @@ void 
 MainWindow::about()
 {
 	const char* svn_version();
-	QMessageBox::about(this, "About", QString("<font size=\"+2\">Spellathon </font>"VERSION"&nbsp;&nbsp;<font color=\"gray\">(svn%1)</font><br><br>&copy;"COPYRIGHT"<br>").arg(svn_version()));
+	QMessageBox::about(this, "About", QString("<font size=\"+2\">Spellathon </font>" VERSION "&nbsp;&nbsp;<font color=\"gray\">(svn%1)</font><br><br>&copy;" COPYRIGHT "<br>").arg(svn_version()));
 }
 
 void 
