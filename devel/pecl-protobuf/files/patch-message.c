--- message.c.orig	2020-08-15 00:45:27 UTC
+++ message.c
@@ -265,14 +265,14 @@ static PROTO_RETURN_VAL Message_write_property(
   }
 
   upb_msg_set(intern->msg, f, msgval, arena);
-#if PHP_VERSION_ID < 704000
+#if PHP_VERSION_ID < 70400
   return;
 #else
   return val;
 #endif
 
 error:
-#if PHP_VERSION_ID < 704000
+#if PHP_VERSION_ID < 70400
   return;
 #else
   return &EG(error_zval);
