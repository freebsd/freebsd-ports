--- tlsutil.c.orig	Tue Sep  9 02:55:27 2003
+++ tlsutil.c	Tue Sep  9 02:57:58 2003
@@ -218,6 +218,13 @@
     	fclose(file);
 	return fn;
     }
+
+    snprintf(fp, sizeof(fp), "%s/%s", "%%PREFIX%%" "/etc/ftpd-tls", fn);
+    if ((file = fopen(fp, "r"))) {
+    	fclose(file);
+	return fp;
+    }
+
     if (!(dir = getenv(X509_get_default_cert_dir_env())))  /* $SSL_CERT_DIR */
     	dir = (char *) X509_get_default_cert_dir();
     snprintf(fp, sizeof(fp), "%s/%s", dir, fn);
