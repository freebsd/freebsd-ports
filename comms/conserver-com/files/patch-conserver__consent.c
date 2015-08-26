--- conserver/consent.c.dist	2015-08-12 13:38:39.837321000 -0700
+++ conserver/consent.c	2015-08-12 13:38:01.860668000 -0700
@@ -687,6 +687,10 @@
 	case INSSLSHUTDOWN:
 	    return "SSL_shutdown";
 #endif
+#if HAVE_GSSAPI
+	case INGSSACCEPT:
+	    return "GSSAPI_accept";
+#endif
 	case ISFLUSHING:
 	    return "flushing";
     }
