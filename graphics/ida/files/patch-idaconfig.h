--- idaconfig.h.orig	2017-08-30 10:48:03 UTC
+++ idaconfig.h
@@ -17,7 +17,7 @@
 
 /* -------------------------------------------------------------------------- */
 
-char *ida_lists;
+extern char *ida_lists;
 
 void ida_init_config(void);
 void ida_read_config(void);
