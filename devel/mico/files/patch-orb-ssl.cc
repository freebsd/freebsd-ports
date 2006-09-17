--- orb/ssl.cc.orig	Sun Sep 17 01:11:12 2006
+++ orb/ssl.cc	Sun Sep 17 01:11:36 2006
@@ -800,9 +800,7 @@
     if (!fp)
 	return NULL;
 
-    x509 = (X509 *)PEM_ASN1_read ((char *(*)())d2i_X509,
-				  PEM_STRING_X509,
-				  fp, NULL, NULL,NULL);
+    x509 = PEM_read_X509 (fp, NULL, NULL,NULL);
 
     if (x509 == NULL) {
 	//ERR_print_errors_fp (stderr);
