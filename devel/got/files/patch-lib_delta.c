--- lib/delta.c.orig	2025-07-26 10:40:07 UTC
+++ lib/delta.c
@@ -321,7 +321,8 @@ got_delta_apply_in_mem(uint8_t *base_buf, size_t base_
 	if (err == NULL && *outsize != result_size)
 		err = got_error_fmt(GOT_ERR_BAD_DELTA,
 		    "delta application result size mismatch: actual: %zd "
-		    "expected: %llu", *outsize, result_size);
+		    "expected: %llu", *outsize,
+		    (unsigned long long)result_size);
 
 	return err;
 }
@@ -390,7 +391,8 @@ got_delta_apply(FILE *base_file, const uint8_t *delta_
 	if (err == NULL && *outsize != result_size)
 		err = got_error_fmt(GOT_ERR_BAD_DELTA,
 		    "delta application result size mismatch: actual: %zd "
-		    "expected: %llu", *outsize, result_size);
+		    "expected: %llu", *outsize,
+		    (unsigned long long)result_size);
 
 	if (memstream != NULL) {
 		if (fclose(memstream) == EOF && err == NULL)
