--- rf/umain.h.orig	2002-01-02 17:46:33.000000000 +0100
+++ rf/umain.h	2007-11-14 00:02:57.000000000 +0100
@@ -690,7 +690,7 @@
 	} UDispatchInfo;
 
 	//! dispatch an event using the static message table.
-	virtual int UDispatchMessage(int/*UEventType*/ evt, int arg1, void *arg2, UDispatchInfo & dispatchInfo);
+	virtual int UDispatchMessage(int/*UEventType*/ evt, int arg1, const void *arg2, UDispatchInfo & dispatchInfo);
 
 	inline int GetWidID(void) const { return m_widid; }
 private:
@@ -969,7 +969,7 @@
 extern "C" {
 #endif
 
-UEXPORT int UEventSendMessage(int wid, int/*UEventType*/ evt, int arg1, void *arg2);
+UEXPORT int UEventSendMessage(int wid, int/*UEventType*/ evt, int arg1, const void *arg2);
 	/* send a message to a pseudo-widget */
 
 UEXPORT int UEventSendMessageExt(int wid, int/*UEventType*/ evt, int arg1, void *arg2, int * handledFlag);
