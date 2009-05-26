--- CodeLite/clindexerprotocol.cpp.orig	2009-05-26 14:27:26.000000000 +0200
+++ CodeLite/clindexerprotocol.cpp	2009-05-26 14:30:37.000000000 +0200
@@ -25,7 +25,7 @@
 	}
 
 	if (actual_read != sizeof(buff_len)) {
-		fprintf(stderr, "ERROR: ReadReply: Protocol error: expected %d bytes, got %d. reason: %d\n",
+		fprintf(stderr, "ERROR: ReadReply: Protocol error: expected %zu bytes, got %zu. reason: %d\n",
 				sizeof(buff_len),
 				actual_read,
 				conn->getLastError());
@@ -39,7 +39,7 @@
 	size_t bytes_read(0);
 	while (bytes_left > 0) {
 		if ( !conn->read(data+bytes_read, bytes_left, &actual_read, 10000) ) {
-			fprintf(stderr, "ERROR: Protocol error: expected %d bytes, got %d\n", buff_len, actual_read);
+			fprintf(stderr, "ERROR: Protocol error: expected %zu bytes, got %zu\n", buff_len, actual_read);
 			return false;
 		}
 		bytes_left -= actual_read;
@@ -71,7 +71,7 @@
 	}
 
 	if (actual_read != sizeof(buff_len)) {
-		fprintf(stderr, "ERROR: Protocol error: expected %d bytes, got %d\n", sizeof(buff_len), actual_read);
+		fprintf(stderr, "ERROR: Protocol error: expected %zu bytes, got %zu\n", sizeof(buff_len), actual_read);
 		return false;
 	}
 
@@ -82,7 +82,7 @@
 	size_t bytes_read(0);
 	while (bytes_left > 0) {
 		if ( !conn->read(data+bytes_read, bytes_left, &actual_read, -1) ) {
-			fprintf(stderr, "ERROR: [%s] Protocol error: expected %d bytes, got %d\n", __PRETTY_FUNCTION__, buff_len, actual_read);
+			fprintf(stderr, "ERROR: [%s] Protocol error: expected %zu bytes, got %zu\n", __PRETTY_FUNCTION__, buff_len, actual_read);
 			return false;
 		}
 		bytes_left -= actual_read;
