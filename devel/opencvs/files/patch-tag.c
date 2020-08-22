--- tag.c.orig	2016-02-06 22:25:26 UTC
+++ tag.c
@@ -34,7 +34,7 @@ void	cvs_tag_local(struct cvs_file *);
 static int tag_del(struct cvs_file *);
 static int tag_add(struct cvs_file *);
 
-struct file_info_list	files_info;
+extern struct file_info_list	files_info;
 
 static int	 runflags = 0;
 static char	*tag = NULL;
