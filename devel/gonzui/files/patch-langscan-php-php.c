--- langscan/php/php.c-	Mon Feb  7 11:17:11 2005
+++ langscan/php/php.c	Mon Feb  7 11:17:27 2005
@@ -31,9 +31,9 @@
 {
   VALUE user_io = (VALUE)*user_data_p;
   VALUE str = rb_funcall(user_io, id_read, 1, INT2NUM(maxlen));
+  size_t len = maxlen;
   if (NIL_P(str))
     return 0;
-  size_t len = maxlen;
   StringValue(str);
   if (RSTRING(str)->len < len)
     len = RSTRING(str)->len;
