--- src/digest_auth_orig.c	2000-12-03 08:25:44.000000000 -0600
+++ src/digest_auth.c	2004-07-24 13:45:50.000000000 -0500
@@ -87,6 +87,7 @@
 	return retv;
 }
 
+/* PRE: Assumes 'buf' can store 2K */
 char *http_get_digest_auth_str(auth_digest, method, user, pass, urlp, buf)
 http_digest_info *auth_digest;
 char *method;
@@ -99,14 +100,15 @@
 	char *a1,*a2,*a3;
 	char *d = url_encode_str(urlp->p.http.document, URL_PATH_UNSAFE);
 
-	sprintf(pom, "%s:%s:%s", user, auth_digest->realm, pass);
+	snprintf(pom, sizeof(pom), "%s:%s:%s", user, auth_digest->realm, pass);
 	a1 = _md5(pom);
-	sprintf(pom, "%s:%s", method, d);
+	snprintf(pom, sizeof(pom), "%s:%s", method, d);
 	a2 = _md5(pom);
-	sprintf(pom, "%s:%s:%s", a1, auth_digest->nonce, a2);
+	snprintf(pom, sizeof(pom), "%s:%s:%s", a1, auth_digest->nonce, a2);
 	a3 = _md5(pom);
 
-	sprintf(buf,
+	snprintf(buf,
+		2048,
 		"Digest username=\"%s\", realm=\"%s\", nonce=\"%s\", uri=\"%s\", response=\"%s\"" , 
 		user, auth_digest->realm, auth_digest->nonce, d, a3);
 
