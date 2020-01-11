--- tests/test_parse.c.orig	2018-01-16 04:33:49 UTC
+++ tests/test_parse.c
@@ -253,11 +253,11 @@ struct incremental_step {
 	   the next few tests check that parsing multiple sequential
        json objects in the input works as expected */
 	{ "null123",           9, 4, json_tokener_success, 0 },
-	{ "null123" + 4,       4, 3, json_tokener_success, 1 },
+	{ &"null123"[4],       4, 3, json_tokener_success, 1 },
 	{ "nullx",             5, 4, json_tokener_success, 0 },
-	{ "nullx" + 4,         2, 0, json_tokener_error_parse_unexpected, 1 },
+	{ &"nullx"[4],         2, 0, json_tokener_error_parse_unexpected, 1 },
 	{ "{\"a\":1}{\"b\":2}",15, 7, json_tokener_success, 0 },
-	{ "{\"a\":1}{\"b\":2}" + 7,
+	{ &"{\"a\":1}{\"b\":2}"[7],
 	                       8, 7, json_tokener_success, 1 },
 
 	/* Some bad formatting. Check we get the correct error status */
