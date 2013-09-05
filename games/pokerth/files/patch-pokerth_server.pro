--- pokerth_server.pro.orig	2013-04-07 14:04:26.923209000 +0200
+++ pokerth_server.pro	2013-09-05 14:53:56.604074418 +0200
@@ -265,7 +265,7 @@
 			-lprotobuf
 	LIBS += -lgsasl
 	!isEmpty( BSD ): isEmpty( kFreeBSD ){
-		LIBS += -lcrypto -liconv
+		LIBS += -lcrypto -liconv -lssl
 	} else {
 		LIBS += -lgcrypt
 	}
