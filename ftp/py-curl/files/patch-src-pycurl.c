--- src/pycurl.c.orig	Fri Aug 11 10:37:19 2006
+++ src/pycurl.c	Wed Dec 20 16:11:36 2006
@@ -1475,9 +1475,11 @@
         case CURLOPT_URL:
         case CURLOPT_USERAGENT:
         case CURLOPT_USERPWD:
+#if LIBCURL_VERSION_NUM < 0x071000
         case CURLOPT_SOURCE_HOST:
         case CURLOPT_SOURCE_USERPWD:
         case CURLOPT_SOURCE_PATH:
+#endif
         case CURLOPT_FTP_ALTERNATIVE_TO_USER:
 /* FIXME: check if more of these options allow binary data */
             str = PyString_AsString_NoNUL(obj);
@@ -1646,12 +1648,14 @@
         case CURLOPT_PREQUOTE:
             old_slist = &self->prequote;
             break;
+#if LIBCURL_VERSION_NUM < 0x071000
         case CURLOPT_SOURCE_PREQUOTE:
             old_slist = &self->source_prequote;
             break;
         case CURLOPT_SOURCE_POSTQUOTE:
             old_slist = &self->source_postquote;
             break;
+#endif
         case CURLOPT_HTTPPOST:
             break;
         default:
@@ -3180,14 +3184,18 @@
     insint_c(d, "FTP_SSL", CURLOPT_FTP_SSL);
     insint_c(d, "POSTFIELDSIZE_LARGE", CURLOPT_POSTFIELDSIZE_LARGE);
     insint_c(d, "TCP_NODELAY", CURLOPT_TCP_NODELAY);
+#if LIBCURL_VERSION_NUM < 0x071000
     insint_c(d, "SOURCE_USERPWD", CURLOPT_SOURCE_USERPWD);
     insint_c(d, "SOURCE_PREQUOTE", CURLOPT_SOURCE_PREQUOTE);
     insint_c(d, "SOURCE_POSTQUOTE", CURLOPT_SOURCE_POSTQUOTE);
+#endif
     insint_c(d, "FTPSSLAUTH", CURLOPT_FTPSSLAUTH);
     insint_c(d, "IOCTLFUNCTION", CURLOPT_IOCTLFUNCTION);
     insint_c(d, "IOCTLDATA", CURLOPT_IOCTLDATA);
+#if LIBCURL_VERSION_NUM < 0x071000
     insint_c(d, "SOURCE_URL", CURLOPT_SOURCE_URL);
     insint_c(d, "SOURCE_QUOTE", CURLOPT_SOURCE_QUOTE);
+#endif
     insint_c(d, "FTP_ACCOUNT", CURLOPT_FTP_ACCOUNT);
     insint_c(d, "IGNORE_CONTENT_LENGTH", CURLOPT_IGNORE_CONTENT_LENGTH);
     insint_c(d, "COOKIELIST", CURLOPT_COOKIELIST);
