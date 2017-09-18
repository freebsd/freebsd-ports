--- pokerth_server.pro.orig	2014-01-10 21:18:20 UTC
+++ pokerth_server.pro
@@ -264,7 +264,7 @@ unix : !mac {
 			-lprotobuf
 	LIBS += -lgsasl
 	!isEmpty( BSD ): isEmpty( kFreeBSD ){
-		LIBS += -lcrypto -liconv
+		LIBS += -lcrypto -liconv -lssl
 	} else {
 		LIBS += -lgcrypt
 	}
