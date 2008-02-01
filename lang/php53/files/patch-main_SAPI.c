--- main/SAPI.c.orig	2007-05-25 11:20:01.000000000 +0200
+++ main/SAPI.c	2008-02-01 23:48:51.000000000 +0100
@@ -301,6 +301,7 @@
 
 	/* SG(sapi_headers).http_response_code = 200; */ 
 	SG(sapi_headers).http_status_line = NULL;
+	SG(sapi_headers).mimetype = NULL;
 	SG(read_post_bytes) = 0;
 	SG(request_info).post_data = NULL;
 	SG(request_info).raw_post_data = NULL;
@@ -340,6 +341,7 @@
 	SG(sapi_headers).http_response_code = 200;
 	*/
 	SG(sapi_headers).http_status_line = NULL;
+	SG(sapi_headers).mimetype = NULL;
 	SG(headers_sent) = 0;
 	SG(read_post_bytes) = 0;
 	SG(request_info).post_data = NULL;
@@ -604,7 +606,7 @@
 					ptr++;
 					len--;
 				}
-#if HAVE_ZLIB
+#if 1
 				if(!strncmp(ptr, "image/", sizeof("image/")-1)) {
 					zend_alter_ini_entry("zlib.output_compression", sizeof("zlib.output_compression"), "0", sizeof("0") - 1, PHP_INI_USER, PHP_INI_STAGE_RUNTIME);
 				}
@@ -758,7 +760,7 @@
 		return SUCCESS;
 	}
 
-#if HAVE_ZLIB
+#if 1
 	/* Add output compression headers at this late stage in order to make
 	   it possible to switch it off inside the script. */
 
