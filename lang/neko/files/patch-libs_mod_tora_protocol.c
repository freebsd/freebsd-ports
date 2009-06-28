--- libs/mod_tora/protocol.c.orig	2009-06-19 17:15:56.000000000 +0900
+++ libs/mod_tora/protocol.c	2009-06-19 17:17:33.000000000 +0900
@@ -37,7 +37,7 @@
 			cursor++; \
 	}
 
-static int pwrite( mcontext *c, const char *buf, int len ) {
+static int _pwrite( mcontext *c, const char *buf, int len ) {
 	while( len > 0 ) {
 		int k = send(c->sock,buf,len,MSG_NOSIGNAL);
 		if( k <= 0 ) return 0;
@@ -47,7 +47,7 @@
 	return 1;
 }
 
-static int pread( mcontext *c, char *buf, int len ) {
+static int _pread( mcontext *c, char *buf, int len ) {
 	while( len > 0 ) {
 		int k = recv(c->sock,buf,len,MSG_NOSIGNAL);
 		if( k <= 0 ) return 0;
@@ -63,8 +63,8 @@
 	h[1] = (unsigned char)len;
 	h[2] = (unsigned char)(len >> 8);
 	h[3] = (unsigned char)(len >> 16);
-	pwrite(c,(char*)h,4);
-	pwrite(c,str,len);
+	_pwrite(c,(char*)h,4);
+	_pwrite(c,str,len);
 }
 
 static void psend( mcontext *c, proto_code code, const char *str ) {
@@ -329,7 +329,7 @@
 	int buflen = BUFSIZE;
 	*exc = 0;
 	while( true ) {
-		if( !pread(c,header,4) )
+		if( !_pread(c,header,4) )
 			ABORT("Connection Closed");
 		len = header[1] | (header[2] << 8) | (header[3] << 16);
 		if( buflen <= len ) {
@@ -338,7 +338,7 @@
 			free(buf);
 			buf = (char*)malloc(buflen);
 		}
-		if( !pread(c,buf,len) )
+		if( !_pread(c,buf,len) )
 			ABORT("Connection Closed");
 		buf[len] = 0;
 		switch( *header ) {
