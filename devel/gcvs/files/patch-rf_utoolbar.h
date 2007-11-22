--- rf/utoolbar.h.orig	2007-11-14 00:07:09.000000000 +0100
+++ rf/utoolbar.h	2007-11-14 00:07:18.000000000 +0100
@@ -85,7 +85,7 @@
 	UToolbar(int widid);
 	virtual ~UToolbar();
 
-	virtual int UDispatchMessage(int/*UEventType*/ evt, int arg1, void *arg2, UDispatchInfo & dispatchInfo);
+	virtual int UDispatchMessage(int/*UEventType*/ evt, int arg1, const void *arg2, UDispatchInfo & dispatchInfo);
 
 protected:
 	ev_msg void OnDestroy();
