--- oci8_lob.c.orig	Sat May 26 09:41:51 2007
+++ oci8_lob.c	Sat May 26 09:45:36 2007
@@ -301,6 +301,7 @@
 	}
 
 	if (is_clob) {
+#ifdef OCI_NLS_CHARSET_MAXBYTESZ
 		PHP_OCI_CALL_RETURN(connection->errcode, OCINlsNumericInfoGet, (connection->env, connection->err, &bytes_per_char, OCI_NLS_CHARSET_MAXBYTESZ));
 
 		if (connection->errcode != OCI_SUCCESS) {
@@ -308,6 +309,9 @@
 			PHP_OCI_HANDLE_ERROR(connection, connection->errcode);
 			return 1;
 		}
+#else
+		bytes_per_char = 4;
+#endif
 	} else {
 		/* BLOBs don't have encoding, so bytes_per_char == 1 */
 	}
