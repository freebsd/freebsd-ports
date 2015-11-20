--- src/mumble.pri.orig	2015-07-09 13:23:46 UTC
+++ src/mumble.pri
@@ -54,7 +54,7 @@ unix {
 	LIBS *= -lprotobuf
 
 	contains(UNAME, FreeBSD) {
-		LIBS *= -lcrypto
+		LIBS *= -lcrypto -lssl
 	} else {
 		PKGCONFIG *= openssl
 	}
