--- src/modules/notifier/notifierwindowtabs.cpp.orig	Sun Apr 17 00:58:15 2005
+++ src/modules/notifier/notifierwindowtabs.cpp	Sun Apr 17 00:58:36 2005
@@ -228,7 +228,7 @@
 
 void KviNotifierWindowTabs::addMessage(KviWindow * pWnd, KviNotifierMessage * message)
 {
-	QString sender = pWnd ? pWnd->windowName() : "----";
+	QString sender = pWnd ? pWnd->windowName() : (QString)"----";
 
 	// Qui servirebbe anche una lista... perche' quando si inserisce
 	// un tab lui lo piazza dove gli pare nell'ordine
