--- src/mysql/mainwindow/mainwindowslotshutdown.cxx.orig	Tue Mar  5 07:13:22 2002
+++ src/mysql/mainwindow/mainwindowslotshutdown.cxx	Fri Dec 31 12:49:00 2004
@@ -9,7 +9,11 @@
 	if(z == 1)
 		return;
 		
+#if  ( MYSQL_VERSION_ID >= 40103 && MYSQL_VERSION_ID < 50000 ) || ( MYSQL_VERSION_ID >= 50001 )
+	if(mysql_shutdown(&mysql, SHUTDOWN_DEFAULT))
+#else
 	if(mysql_shutdown(&mysql))
+#endif
 	{
 		QMessageBox::critical(this, tr("MySQL Navigator"), QString::fromLocal8Bit(mysql_error(&mysql)));
 	}
