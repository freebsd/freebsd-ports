--- modules/curl/curl.c.orig	Fri Dec  8 18:58:07 2006
+++ modules/curl/curl.c	Fri Dec  8 18:59:12 2006
@@ -461,7 +461,9 @@
   CURLOPT_WRITEFUNCTION,
   CURLOPT_READFUNCTION,
   CURLOPT_PROGRESSFUNCTION,
+#if LIBCURL_VERSION_NUM < 0x071000
   CURLOPT_PASSWDFUNCTION,
+#endif
   CURLOPT_HEADERFUNCTION,
   CURLOPT_DEBUGFUNCTION,
 
@@ -660,7 +662,9 @@
      mkint(CURLOPT_WRITEFUNCTION),
      mkint(CURLOPT_READFUNCTION),
      mkint(CURLOPT_PROGRESSFUNCTION),
+#if LIBCURL_VERSION_NUM < 0x071000
      mkint(CURLOPT_PASSWDFUNCTION),
+#endif
      mkint(CURLOPT_HEADERFUNCTION),
      mkint(CURLOPT_DEBUGFUNCTION),
 
@@ -964,10 +968,12 @@
 	cb = (int(*)())progress_cb;
 	dataopt = CURLOPT_PROGRESSDATA;
 	break;
+#if LIBCURL_VERSION_NUM < 0x071000
       case CURLOPT_PASSWDFUNCTION:
 	cb = (int(*)())passwd_cb;
 	dataopt = CURLOPT_PASSWDDATA;
 	break;
+#endif
       case CURLOPT_HEADERFUNCTION:
 	cb = (int(*)())header_cb;
 	dataopt = CURLOPT_WRITEHEADER;
