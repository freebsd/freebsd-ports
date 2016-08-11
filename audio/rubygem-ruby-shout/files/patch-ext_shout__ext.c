--- ext/shout_ext.c.orig	2016-07-26 15:50:39 UTC
+++ ext/shout_ext.c
@@ -250,7 +250,7 @@ static VALUE _sh_send(VALUE self, VALUE 
         shout_connection *s;
         GET_SC(self, s);
 
-        Check_SafeStr(to_send);
+        SafeStringValue(to_send);
         err = shout_send(s->conn, (unsigned char *) (RSTRING_PTR(to_send)),
                                   RSTRING_LEN(to_send));
         if(err != SHOUTERR_SUCCESS) {
