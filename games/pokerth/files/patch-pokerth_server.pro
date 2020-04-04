--- pokerth_server.pro.orig	2017-08-16 12:24:03 UTC
+++ pokerth_server.pro
@@ -288,7 +288,7 @@ unix : !mac {
 			-lprotobuf
 	LIBS += -lgsasl
 	!isEmpty( BSD ): isEmpty( kFreeBSD ){
-		LIBS += -lcrypto -liconv
+		LIBS += -lcrypto -liconv -lssl
 	} else {
 		LIBS += -lgcrypt
 	}
