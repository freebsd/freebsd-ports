--- src/libwaitress/waitress.h.orig	2011-11-11 03:37:58.000000000 -0800
+++ src/libwaitress/waitress.h	2011-11-21 23:34:09.000000000 -0800
@@ -82,7 +82,8 @@
 
 /*	reusable handle
  */
-typedef struct {
+struct WaitressHandle_t;
+typedef struct WaitressHandle_t {
 	WaitressUrl_t url;
 	WaitressMethod_t method;
 	const char *extraHeaders;
@@ -102,9 +103,9 @@
 		char *buf;
 		gnutls_session_t tlsSession;
 		/* first argument is WaitressHandle_t, but that's not defined here */
-		WaitressHandlerReturn_t (*dataHandler) (void *, char *, const size_t);
-		ssize_t (*read) (void *, char *, const size_t, ssize_t *);
-		ssize_t (*write) (void *, const char *, const size_t);
+		WaitressHandlerReturn_t (*dataHandler) (struct WaitressHandle_t *, char *, const size_t);
+		WaitressReturn_t (*read) (struct WaitressHandle_t *, char *, const size_t, ssize_t *);
+		WaitressReturn_t (*write) (struct WaitressHandle_t *, const char *, const size_t);
 		/* temporary return value storage */
 		WaitressReturn_t readWriteRet;
 	} request;
