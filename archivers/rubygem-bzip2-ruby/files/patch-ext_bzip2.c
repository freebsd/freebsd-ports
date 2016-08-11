--- ext/bzip2.c.orig	2016-07-26 12:25:25 UTC
+++ ext/bzip2.c
@@ -247,9 +247,6 @@ static VALUE bz_writer_close(VALUE obj) 
 
     Get_BZ2(obj, bzf);
     res = bz_writer_internal_close(bzf);
-    if (!NIL_P(res) && (bzf->flags & BZ2_RB_INTERNAL)) {
-        RBASIC(res)->klass = rb_cString;
-    }
     return res;
 }
 
