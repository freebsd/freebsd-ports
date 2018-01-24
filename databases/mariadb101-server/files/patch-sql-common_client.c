--- sql-common/client.c.orig	2018-01-24 00:36:45.520273000 +0100
+++ sql-common/client.c	2018-01-24 00:37:57.536367000 +0100
@@ -1821,7 +1821,8 @@
   */
 
 #ifdef HAVE_X509_check_host
-  ret_validation= X509_check_host(server_cert, server_hostname, 0, 0, 0) != 1;
+  ret_validation= X509_check_host(server_cert, server_hostname,
+                                  strlen(server_hostname), 0, 0) != 1;
 #else
   subject= X509_get_subject_name(server_cert);
   cn_loc= X509_NAME_get_index_by_NID(subject, NID_commonName, -1);
