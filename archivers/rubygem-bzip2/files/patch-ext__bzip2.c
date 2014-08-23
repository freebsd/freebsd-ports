--- ./ext/bzip2.c.orig	2014-08-23 18:00:07.743290567 +0000
+++ ./ext/bzip2.c	2014-08-23 18:00:07.790289811 +0000
@@ -247,9 +247,6 @@
 
     Get_BZ2(obj, bzf);
     res = bz_writer_internal_close(bzf);
-    if (!NIL_P(res) && (bzf->flags & BZ2_RB_INTERNAL)) {
-        RBASIC(res)->klass = rb_cString;
-    }
     return res;
 }
 
