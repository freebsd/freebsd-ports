--- src/libwaitress/waitress.c.orig	2011-11-11 03:37:58.000000000 -0800
+++ src/libwaitress/waitress.c	2011-11-21 23:34:11.000000000 -0800
@@ -443,10 +443,11 @@
  *	@param write count bytes
  *	@return number of written bytes or -1 on error
  */
-static ssize_t WaitressPollWrite (WaitressHandle_t *waith,
-		const char *buf, size_t count) {
+static ssize_t WaitressPollWrite (void *wptr, const void *bptr, size_t count) {
 	int pollres = -1;
 	ssize_t retSize;
+	WaitressHandle_t *waith = wptr;
+	const char *buf = bptr;
 
 	assert (waith != NULL);
 	assert (buf != NULL);
@@ -489,10 +490,11 @@
  *	@param buffer size
  *	@return number of read bytes or -1 on error
  */
-static ssize_t WaitressPollRead (WaitressHandle_t *waith, char *buf,
-		size_t count) {
+static ssize_t WaitressPollRead (void *wptr, void *bptr, size_t count) {
 	int pollres = -1;
 	ssize_t retSize;
+	WaitressHandle_t *waith = wptr;
+	char *buf = bptr;
 
 	assert (waith != NULL);
 	assert (buf != NULL);
@@ -515,7 +517,7 @@
 }
 
 static WaitressReturn_t WaitressOrdinaryRead (WaitressHandle_t *waith,
-		char *buf, const size_t size, size_t *retSize) {
+		char *buf, const size_t size, ssize_t *retSize) {
 	const ssize_t ret = WaitressPollRead (waith, buf, size);
 	if (ret != -1) {
 		*retSize = ret;
@@ -524,7 +526,7 @@
 }
 
 static WaitressReturn_t WaitressGnutlsRead (WaitressHandle_t *waith,
-		char *buf, const size_t size, size_t *retSize) {
+		char *buf, const size_t size, ssize_t *retSize) {
 	ssize_t ret = gnutls_record_recv (waith->request.tlsSession, buf, size);
 	if (ret < 0) {
 		return WAITRESS_RET_TLS_READ_ERR;
@@ -809,7 +811,7 @@
 		/* set up proxy tunnel */
 		if (WaitressProxyEnabled (waith)) {
 			char buf[256];
-			size_t size;
+			ssize_t size;
 			snprintf (buf, sizeof (buf), "CONNECT %s:%s HTTP/"
 					WAITRESS_HTTP_VERSION "\r\n\r\n",
 					waith->url.host, WaitressDefaultPort (&waith->url));
