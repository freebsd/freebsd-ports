--- src/modules/notifier/notifierwindowtabs.cpp.orig	Sun Jan  7 10:39:57 2007
+++ src/modules/notifier/notifierwindowtabs.cpp	Sat Jan 27 18:24:16 2007
@@ -237,7 +237,7 @@
 
 void KviNotifierWindowTabs::addMessage(KviWindow * pWnd, KviNotifierMessage * message)
 {
-	QString sender = pWnd ? pWnd->windowName() : "----";
+	QString sender = pWnd ? pWnd->windowName() : (QString)"----";
 
 	// Qui servirebbe anche una lista... perche' quando si inserisce
 	// un tab lui lo piazza dove gli pare nell'ordine
