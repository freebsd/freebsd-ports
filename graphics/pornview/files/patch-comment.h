--- src/comment.h.orig	2002-12-22 11:18:51.000000000 +0100
+++ src/comment.h	2009-04-19 14:34:10.000000000 +0200
@@ -18,10 +18,10 @@
 #include "image_info.h"
 
 #define TYPE_COMMENT            (comment_get_type ())
-#define COMMENT(obj)            (GTK_CHECK_CAST ((obj), TYPE_COMMENT, Comment))
-#define COMMENT_CLASS(klass)    (GTK_CHECK_CLASS_CAST ((klass), TYPE_COMMENT, CommentClass))
-#define IS_COMMENT(obj)         (GTK_CHECK_TYPE ((obj), TYPE_COMMENT))
-#define IS_COMMENT_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), TYPE_COMMENT))
+#define COMMENT(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMMENT, Comment))
+#define COMMENT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMMENT, CommentClass))
+#define IS_COMMENT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMMENT))
+#define IS_COMMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMMENT))
 
 typedef struct Comment_Tag Comment;
 typedef struct CommentClass_Tag CommentClass;
@@ -64,7 +64,7 @@
 CommentDataEntry;
 
 
-guint           comment_get_type (void);
+GType           comment_get_type (void);
 Comment        *comment_ref (Comment * comment);
 void            comment_unref (Comment * comment);
 
