--- lib/cookie.c.orig	2019-03-25 08:42:50 UTC
+++ lib/cookie.c
@@ -1085,6 +1085,8 @@ Curl_cookie_add(struct Curl_easy *data,
   return co;
 }
 
+#endif /* CURL_DISABLE_HTTP || CURL_DISABLE_COOKIES */
+
 /*
  * get_line() makes sure to only return complete whole lines that fit in 'len'
  * bytes and end with a newline.
@@ -1112,6 +1114,7 @@ char *Curl_get_line(char *buf, int len, 
   return NULL;
 }
 
+#if !defined(CURL_DISABLE_HTTP) && !defined(CURL_DISABLE_COOKIES)
 
 /*****************************************************************************
  *
