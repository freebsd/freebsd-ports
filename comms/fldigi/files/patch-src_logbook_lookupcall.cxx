--- src/logbook/lookupcall.cxx.orig	2013-11-18 09:00:51.559614995 -0500
+++ src/logbook/lookupcall.cxx	2013-11-18 16:31:56.283748901 -0500
@@ -1180,7 +1180,7 @@
 			return NULL;
 
 		size_t p;
-		if (fetch_http(EQSL_url, EQSL_xmlpage, 5.0) == -1)
+		if (fetch_http(EQSL_url, EQSL_xmlpage, 5.0) == false)
 			LOG_ERROR("%s", "eQSL not available");
 
 		else if ((p = EQSL_xmlpage.find("Error:")) != std::string::npos) {
