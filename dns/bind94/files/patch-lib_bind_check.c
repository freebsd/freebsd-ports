--- lib/bind9/check.c.orig	2007-09-12 22:04:01.000000000 -0700
+++ lib/bind9/check.c	2008-07-11 11:51:01.000000000 -0700
@@ -1015,10 +1015,10 @@
 	isc_buffer_add(&b, strlen(zname));
 	tresult = dns_name_fromtext(dns_fixedname_name(&fixedname), &b,
 				   dns_rootname, ISC_TRUE, NULL);
-	if (result != ISC_R_SUCCESS) {
+	if (tresult != ISC_R_SUCCESS) {
 		cfg_obj_log(zconfig, logctx, ISC_LOG_ERROR,
 			    "zone '%s': is not a valid name", zname);
-		tresult = ISC_R_FAILURE;
+		result = ISC_R_FAILURE;
 	} else {
 		char namebuf[DNS_NAME_FORMATSIZE];
 
