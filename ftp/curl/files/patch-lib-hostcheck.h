--- lib/hostcheck.h.orig	2013-09-09 06:11:15.000000000 +0800
+++ lib/hostcheck.h	2014-03-28 00:39:25.052513814 +0800
@@ -23,6 +23,7 @@
  ***************************************************************************/
 
 #include <curl/curl.h>
+#include <netinet/in.h>
 
 #define CURL_HOST_NOMATCH 0
 #define CURL_HOST_MATCH   1
