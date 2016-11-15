--- src/dboxfe.cpp.orig	2007-09-22 09:25:00 UTC
+++ src/dboxfe.cpp
@@ -65,7 +65,7 @@ DBoxFE::DBoxFE ( QWidget *parent, Qt::WF
 	connect ( chkBoxStartTrayIcon, SIGNAL ( toggled ( bool ) ), this, SLOT ( slotChkBoxStartTrayIconToggled ( bool ) ) );
 
 	// windows title for the application
-	titleLin = tr ( "DBoxFE - Front End for DOSBox 0.7x - Linux Version " ) + getAppVersion();
+	titleLin = tr ( "DBoxFE" );
 	titleWin = tr ( "DBoxFE - Front End for DOSBox 0.7x - Windows Version " ) + getAppVersion();
 	titleMac = tr ( "DBoxFE - Front End for DOSBox 0.7x - Mac Version " ) + getAppVersion();
 
@@ -83,18 +83,6 @@ DBoxFE::DBoxFE ( QWidget *parent, Qt::WF
 	QApplication::setStyle ( "plastique" );
 #endif
 
-#ifdef Q_OS_UNIX
-	setWindowTitle ( titleLin );
-	QApplication::setStyle ( "plastique" );
-#endif
-
-	// center the application on desktop screen
-	QDesktopWidget *desktop = qApp->desktop();
-	const QRect rect = desktop->availableGeometry ( desktop->primaryScreen() );
-	int left = ( rect.width() - width() ) / 2;
-	int top = ( rect.height() - height() ) / 2;
-	setGeometry ( left, top, width(), height() );
-
 	//for future release :)
 	chkBoxStartTrayIcon->setVisible( false );
 }
