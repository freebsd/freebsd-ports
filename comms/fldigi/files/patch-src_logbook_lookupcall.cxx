--- src/logbook/lookupcall.cxx.orig	2014-03-21 11:25:57.000000000 -0500
+++ src/logbook/lookupcall.cxx	2014-03-21 18:19:53.000000000 -0500
@@ -1188,7 +1188,7 @@
 			return NULL;
 
 		size_t p;
-		if (fetch_http(EQSL_url, EQSL_xmlpage, 5.0) == -1)
+		if (fetch_http(EQSL_url, EQSL_xmlpage, 5.0) == false)
 			LOG_ERROR("%s", "eQSL not available");
 
 		else if ((p = EQSL_xmlpage.find("Error:")) != std::string::npos) {
