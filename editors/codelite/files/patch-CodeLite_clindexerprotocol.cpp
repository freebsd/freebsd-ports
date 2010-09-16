--- sdk/codelite_indexer/network/clindexerprotocol.cpp.orig	2010-09-15 11:53:03.000000000 +0000
+++ sdk/codelite_indexer/network/clindexerprotocol.cpp	2010-09-15 11:54:50.000000000 +0000
@@ -36,7 +36,7 @@
 	}
 
 	if (actual_read != sizeof(buff_len)) {
-		fprintf(stderr, "ERROR: ReadReply: Protocol error: expected %u bytes, got %u. reason: %d\n",
+		fprintf(stderr, "ERROR: ReadReply: Protocol error: expected %zu bytes, got %zu. reason: %d\n",
 				sizeof(buff_len),
 				actual_read,
 				conn->getLastError());
@@ -55,7 +55,7 @@
 	size_t bytes_read(0);
 	while (bytes_left > 0) {
 		if ( !conn->read(data+bytes_read, bytes_left, &actual_read, 10000) ) {
-			fprintf(stderr, "ERROR: Protocol error: expected %u bytes, got %u\n", buff_len, actual_read);
+			fprintf(stderr, "ERROR: Protocol error: expected %zu bytes, got %zu\n", buff_len, actual_read);
 			return false;
 		}
 		bytes_left -= actual_read;
@@ -78,7 +78,7 @@
 	}
 
 	if (actual_read != sizeof(buff_len)) {
-		fprintf(stderr, "ERROR: Protocol error: expected %u bytes, got %u\n", sizeof(buff_len), actual_read);
+		fprintf(stderr, "ERROR: Protocol error: expected %zu bytes, got %zu\n", sizeof(buff_len), actual_read);
 		return false;
 	}
 
@@ -92,7 +92,7 @@
 	size_t bytes_read(0);
 	while (bytes_left > 0) {
 		if ( !conn->read(data+bytes_read, bytes_left, &actual_read, -1) ) {
-			fprintf(stderr, "ERROR: [%s] Protocol error: expected %u bytes, got %u\n", __PRETTY_FUNCTION__, buff_len, actual_read);
+			fprintf(stderr, "ERROR: [%s] Protocol error: expected %zu bytes, got %zu\n", __PRETTY_FUNCTION__, buff_len, actual_read);
 			return false;
 		}
 		bytes_left -= actual_read;
