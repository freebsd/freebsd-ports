???--- uploadprogress.c.orig       2012-05-27 18:32:23.891923716 +0200
+++ uploadprogress.c    2012-05-27 18:33:33.601926257 +0200
@@ -457,11 +457,12 @@
         /* uses mmap if possible */
         if ((len = php_stream_copy_to_mem(stream, &contents, maxlen, 0)) > 0) {

+#if PHP_API_VERSION < 20100412
             if (PG(magic_quotes_runtime)) {
                 contents = php_addslashes(contents, len, &newlen, 1 TSRMLS_CC);
                 len = newlen;
             }
-
+#endif
             RETVAL_STRINGL(contents, len, 0);
         } else if (len == 0) {
             RETVAL_EMPTY_STRING();
