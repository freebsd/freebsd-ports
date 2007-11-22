--- rf/uwidget.h.orig	2007-11-13 23:19:17.000000000 +0100
+++ rf/uwidget.h	2007-11-13 23:19:38.000000000 +0100
@@ -119,7 +119,7 @@
 	virtual void AddListener(UCmdTarget * listener);
 
 	//! this is overided in order to broadcast to the listeners
-	virtual int UDispatchMessage(int/*UEventType*/ evt, int arg1, void *arg2, UDispatchInfo & dispatchInfo);
+	virtual int UDispatchMessage(int/*UEventType*/ evt, int arg1, const void *arg2, UDispatchInfo & dispatchInfo);
 
 	//! return a sub-widget as inserted by EV_INIT_WIDGET
 	//! \arg \c cmd the sub-widget identifier.
