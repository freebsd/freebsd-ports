--- src/comment.c.orig	2002-12-22 11:18:51.000000000 +0100
+++ src/comment.c	2009-04-19 14:33:47.000000000 +0200
@@ -187,7 +187,7 @@
 {
     Comment *comment;
 
-    comment = COMMENT (gtk_type_new (comment_get_type ()));
+    comment = g_object_new (TYPE_COMMENT, NULL);
     g_return_val_if_fail (comment, NULL);
 
     return comment;
@@ -999,10 +999,10 @@
  *-------------------------------------------------------------------
  */
 
-guint
+GType
 comment_get_type (void)
 {
-    static guint comment_type = 0;
+    static GType comment_type = 0;
 
     if (!comment_type)
     {
