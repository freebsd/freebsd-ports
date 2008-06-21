--- sprintf.c.orig	2008-06-21 12:50:30.000000000 +0400
+++ sprintf.c	2008-06-21 12:50:46.000000000 +0400
@@ -247,7 +247,15 @@
     int argc;
     VALUE *argv;
 {
+    return rb_str_format(argc - 1, argv + 1, GETNTHARG(0));
+}
+
+VALUE
+rb_str_format(argc, argv, fmt)
+    int argc;
+    VALUE *argv;
     VALUE fmt;
+{
     const char *p, *end;
     char *buf;
     int blen, bsiz;
@@ -276,7 +284,8 @@
 	rb_raise(rb_eArgError, "flag after precision"); \
     }
 
-    fmt = GETNTHARG(0);
+    ++argc;
+    --argv;
     if (OBJ_TAINTED(fmt)) tainted = 1;
     StringValue(fmt);
     fmt = rb_str_new4(fmt);
