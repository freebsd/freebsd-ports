--- libmowgli-2/src/libmowgli/vio/vio_openssl.c.orig	2012-04-18 22:18:42.000000000 +0200
+++ libmowgli-2/src/libmowgli/vio/vio_openssl.c	2015-10-04 14:31:21.048688880 +0200
@@ -140,7 +140,7 @@ static int mowgli_vio_openssl_listen(mow
 		method = SSLv23_server_method();
 		break;
 	case MOWGLI_VIO_SSLFLAGS_SSLV3:
-		method = SSLv3_server_method();
+		method = SSLv23_server_method();
 		break;
 	case MOWGLI_VIO_SSLFLAGS_TLSV10:
 	case MOWGLI_VIO_SSLFLAGS_TLSV11:
@@ -272,7 +272,7 @@ static int mowgli_vio_openssl_client_han
 		method = SSLv23_client_method();
 		break;
 	case MOWGLI_VIO_SSLFLAGS_SSLV3:
-		method = SSLv3_client_method();
+		method = SSLv23_client_method();
 		break;
 	case MOWGLI_VIO_SSLFLAGS_TLSV10:
 	case MOWGLI_VIO_SSLFLAGS_TLSV11:
