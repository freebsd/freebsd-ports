--- src/pycurl.c.orig	Tue Dec  5 17:11:38 2006
+++ src/pycurl.c	Tue Dec  5 17:13:03 2006
@@ -1109,9 +1109,11 @@
         case CURLOPT_URL:
         case CURLOPT_USERAGENT:
         case CURLOPT_USERPWD:
+#if LIBCURL_VERSION_NUM < 0x071000
         case CURLOPT_SOURCE_HOST:
         case CURLOPT_SOURCE_USERPWD:
         case CURLOPT_SOURCE_PATH:
+#endif
 /* FIXME: check if more of these options allow binary data */
             str = PyString_AsString_NoNUL(obj);
             if (str == NULL)
@@ -1279,12 +1281,14 @@
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
@@ -2689,14 +2693,18 @@
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
