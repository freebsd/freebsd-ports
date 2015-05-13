--- src/logbook/lookupcall.cxx.orig	2015-04-23 11:39:24 UTC
+++ src/logbook/lookupcall.cxx
@@ -1188,7 +1188,7 @@ static void *EQSL_loop(void *args)
 			return NULL;
 
 		size_t p;
-		if (fetch_http(EQSL_url, EQSL_xmlpage, 5.0) == -1)
+		if (fetch_http(EQSL_url, EQSL_xmlpage, 5.0) == false)
 			LOG_ERROR("%s", "eQSL not available");
 
 		else if ((p = EQSL_xmlpage.find("Error:")) != std::string::npos) {
