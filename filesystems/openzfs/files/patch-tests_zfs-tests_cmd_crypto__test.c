--- tests/zfs-tests/cmd/crypto_test.c.orig	2025-05-06 18:18:44 UTC
+++ tests/zfs-tests/cmd/crypto_test.c
@@ -861,7 +861,7 @@ test_result(const crypto_test_t *test, int encrypt_rv,
 		return (pass);
 
 	/* print summary of test result */
-	printf("%s[%lu]: encrypt=%s decrypt=%s\n", test->fileloc, test->id,
+	printf("%s[%" PRIu64 "]: encrypt=%s decrypt=%s\n", test->fileloc, test->id,
 	    encrypt_pass ? "PASS" : "FAIL",
 	    decrypt_pass ? "PASS" : "FAIL");
 
