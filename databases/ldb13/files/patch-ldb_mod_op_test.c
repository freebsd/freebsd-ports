--- tests/ldb_mod_op_test.c.orig	2018-03-02 23:35:09.639709000 +0100
+++ tests/ldb_mod_op_test.c	2018-03-02 23:44:00.194683000 +0100
@@ -3529,7 +3529,7 @@ static void test_ldb_unique_index_duplic
 	assert_int_equal(ret, LDB_SUCCESS);
 
 	msg02 = ldb_msg_new(tmp_ctx);
-	assert_non_null(msg01);
+	assert_non_null(msg02);
 
 	msg02->dn = ldb_dn_new_fmt(msg02, test_ctx->ldb, "dc=test02");
 	assert_non_null(msg02->dn);
