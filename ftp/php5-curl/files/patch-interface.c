--- interface.c.orig	Tue Dec  5 16:50:11 2006
+++ interface.c	Tue Dec  5 16:50:25 2006
@@ -369,7 +369,9 @@
 	REGISTER_CURL_CONSTANT(CURLOPT_FTPAPPEND);
 	REGISTER_CURL_CONSTANT(CURLOPT_NETRC);
 	REGISTER_CURL_CONSTANT(CURLOPT_FOLLOWLOCATION);
+#if CURLOPT_FTPASCII != 0
 	REGISTER_CURL_CONSTANT(CURLOPT_FTPASCII);
+#endif
 	REGISTER_CURL_CONSTANT(CURLOPT_PUT);
 #if CURLOPT_MUTE != 0
 	REGISTER_CURL_CONSTANT(CURLOPT_MUTE);
@@ -409,7 +411,9 @@
 	REGISTER_CURL_CONSTANT(CURLOPT_FILETIME);
 	REGISTER_CURL_CONSTANT(CURLOPT_WRITEFUNCTION);
 	REGISTER_CURL_CONSTANT(CURLOPT_READFUNCTION);
+#if CURLOPT_PASSWDFUNCTION != 0
 	REGISTER_CURL_CONSTANT(CURLOPT_PASSWDFUNCTION);
+#endif
 	REGISTER_CURL_CONSTANT(CURLOPT_HEADERFUNCTION);
 	REGISTER_CURL_CONSTANT(CURLOPT_MAXREDIRS);
 	REGISTER_CURL_CONSTANT(CURLOPT_MAXCONNECTS);
@@ -1158,11 +1162,13 @@
 	dupch->handlers->read->fp = ch->handlers->read->fp;
 	dupch->handlers->read->fd = ch->handlers->read->fd;
 
+#if CURLOPT_PASSWDFUNCTION != 0
 	if (ch->handlers->passwd) {
 		zval_add_ref(&ch->handlers->passwd);
 		dupch->handlers->passwd = ch->handlers->passwd;
 		curl_easy_setopt(ch->cp, CURLOPT_PASSWDDATA, (void *) dupch);
 	}
+#endif
 	if (ch->handlers->write->func_name) {
 		zval_add_ref(&ch->handlers->write->func_name);
 		dupch->handlers->write->func_name = ch->handlers->write->func_name;
@@ -1915,9 +1921,11 @@
 	if (ch->handlers->write_header->func_name) {
 		zval_ptr_dtor(&ch->handlers->write_header->func_name);
 	}
+#if CURLOPT_PASSWDFUNCTION != 0
 	if (ch->handlers->passwd) {
 		zval_ptr_dtor(&ch->handlers->passwd);
 	}
+#endif
 	if (ch->header.str_len > 0) {
 		efree(ch->header.str);
 	}
