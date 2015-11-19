--- src/mumble.pri.orig	2015-11-11 21:54:35 UTC
+++ src/mumble.pri
@@ -53,11 +53,7 @@ unix {
 	CONFIG *= link_pkgconfig
 	LIBS *= -lprotobuf
 
-	contains(UNAME, FreeBSD) {
-		LIBS *= -lcrypto
-	} else {
-		PKGCONFIG *= openssl
-	}
+	PKGCONFIG *= openssl
 }
 
 QMAKE_EXTRA_COMPILERS *= pb pbh
