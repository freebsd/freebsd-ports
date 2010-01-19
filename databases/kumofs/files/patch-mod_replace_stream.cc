--- src/logic/server/mod_replace_stream.cc.orig	2010-01-18 23:49:40.347505120 +0900
+++ src/logic/server/mod_replace_stream.cc	2010-01-18 23:49:59.399149969 +0900
@@ -277,6 +277,17 @@
 		size -= rl;
 	}
 #else
+#ifdef __FreeBSD__
+	size_t sent = 0;
+	while(sent < size) {
+		size_t len = size - sent;
+		off_t sbytes = 0;
+		if(::sendfile(m_fd.get(), sock, sent, len, NULL, &sbytes, 0) < 0) {
+			throw mp::system_error(errno, "offer send error");
+		}
+		sent += sbytes;
+	}
+#else
 	off_t sent = 0;
 	while(sent < size) {
 		off_t len = size - sent;
@@ -286,6 +297,7 @@
 		sent += len;
 	}
 #endif
+#endif
 }
 
 
