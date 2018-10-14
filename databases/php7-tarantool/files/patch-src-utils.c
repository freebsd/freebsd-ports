--- src/utils.c.orig	2018-04-18 13:33:56 UTC
+++ src/utils.c
@@ -29,8 +29,10 @@ const char *tutils_op_to_string(zval *ob
 		return "RESOURCE";
 	case(IS_REFERENCE):
 		return "REFERENCE";
+#if PHP_VERSION_ID < 70300
 	case(IS_CONSTANT):
 		return "CONSTANT";
+#endif
 	case(IS_CONSTANT_AST):
 		return "CONSTANT_AST";
 	case(IS_CALLABLE):
