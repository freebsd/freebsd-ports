error: invalid suffix on literal; C++11 requires a space between literal and identifier
[-Wreserved-user-defined-literal]
        ne_set_useragent(sess, PACKAGE"/"VERSION);

--- src/webservice.cpp.orig	2009-08-17 22:54:07 UTC
+++ src/webservice.cpp
@@ -184,7 +184,7 @@ WebService::get(const std::string &entity,
 	if (!sess) 
 		throw WebServiceError("ne_session_create() failed.");
 	ne_set_server_auth(sess, httpAuth, this);
-	ne_set_useragent(sess, PACKAGE"/"VERSION);
+	ne_set_useragent(sess, PACKAGE "/" VERSION);
 	
 	// Use proxy server
 	if (!d->proxyHost.empty()) {
@@ -269,7 +269,7 @@ WebService::post(const std::string &entity,
 	if (!sess) 
 		throw WebServiceError("ne_session_create() failed.");
 	ne_set_server_auth(sess, httpAuth, this);
-	ne_set_useragent(sess, PACKAGE"/"VERSION);
+	ne_set_useragent(sess, PACKAGE "/" VERSION);
 
 	// Use proxy server
 	if (!d->proxyHost.empty()) {
