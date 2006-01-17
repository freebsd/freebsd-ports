--- driver/connect.c.orig	Sun Oct  9 22:33:40 2005
+++ driver/connect.c	Thu Oct 27 16:44:37 2005
@@ -141,8 +141,10 @@
     client_flag |=  CLIENT_COMPRESS;
   if (option_flag & FLAG_IGNORE_SPACE)
     client_flag |=  CLIENT_IGNORE_SPACE;
-    
+
+#ifdef CLIENT_MULTI_RESULTS
   client_flag |= CLIENT_MULTI_RESULTS;
+#endif
 #ifdef __WIN__
   if (option_flag & FLAG_NAMED_PIPE)
     mysql_options(mysql,MYSQL_OPT_NAMED_PIPE,NullS);
