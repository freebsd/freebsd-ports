--- langscan/c/c.c.orig	Wed Nov 10 18:18:20 2004
+++ langscan/c/c.c	Sat Jan 22 15:06:38 2005
@@ -29,11 +29,11 @@
 
 static size_t user_read_io(void **user_data_p, char *buf, size_t maxlen)
 {
+  size_t len = maxlen;
   VALUE user_io = (VALUE)*user_data_p;
   VALUE str = rb_funcall(user_io, id_read, 1, INT2NUM(maxlen));
   if (NIL_P(str))
     return 0;
-  size_t len = maxlen;
   StringValue(str);
   if (RSTRING(str)->len < len)
     len = RSTRING(str)->len;
