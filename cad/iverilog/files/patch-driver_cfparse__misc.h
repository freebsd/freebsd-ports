--- driver/cfparse_misc.h.orig	2020-08-18 17:06:43 UTC
+++ driver/cfparse_misc.h
@@ -39,6 +39,6 @@ int cferror(const char *);
 int cfparse(void);
 void switch_to_command_file(const char *);
 void destroy_lexor(void);
-char *current_file;
+extern char *current_file;
 
 #endif /* IVL_cfparse_misc_H */
