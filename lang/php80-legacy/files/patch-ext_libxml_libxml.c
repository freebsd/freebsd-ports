--- ext/libxml/libxml.c.orig	2023-08-03 17:13:08 UTC
+++ ext/libxml/libxml.c
@@ -428,7 +428,7 @@ php_libxml_output_buffer_create_filename(const char *U
 static xmlOutputBufferPtr
 php_libxml_output_buffer_create_filename(const char *URI,
                               xmlCharEncodingHandlerPtr encoder,
-                              int compression ATTRIBUTE_UNUSED)
+                              int compression ZEND_ATTRIBUTE_UNUSED)
 {
 	xmlOutputBufferPtr ret;
 	xmlURIPtr puri;
@@ -481,7 +481,11 @@ static void _php_libxml_free_error(void *ptr)
 	xmlResetError((xmlErrorPtr) ptr);
 }
 
+#if LIBXML_VERSION >= 21200
+static void _php_list_set_error_structure(const xmlError *error, const char *msg)
+#else
 static void _php_list_set_error_structure(xmlErrorPtr error, const char *msg)
+#endif
 {
 	xmlError error_copy;
 	int ret;
@@ -732,7 +736,11 @@ PHP_LIBXML_API void php_libxml_ctx_warning(void *ctx, 
 	va_end(args);
 }
 
+#if LIBXML_VERSION >= 21200
+PHP_LIBXML_API void php_libxml_structured_error_handler(void *userData, const xmlError *error)
+#else
 PHP_LIBXML_API void php_libxml_structured_error_handler(void *userData, xmlErrorPtr error)
+#endif
 {
 	_php_list_set_error_structure(error, NULL);
 
@@ -1035,7 +1043,7 @@ PHP_FUNCTION(libxml_get_last_error)
 /* {{{ Retrieve last error from libxml */
 PHP_FUNCTION(libxml_get_last_error)
 {
-	xmlErrorPtr error;
+	const xmlError *error;
 
 	ZEND_PARSE_PARAMETERS_NONE();
 
