--- defs.h.orig	Sat Sep 18 11:08:32 2004
+++ defs.h	Sat Sep 18 11:08:47 2004
@@ -420,10 +420,6 @@
 
 extern int read_relative_register_raw_bytes PARAMS ((int, char *));
 
-/* From readline (but not in any readline .h files).  */
-
-extern char *tilde_expand PARAMS ((char *));
-
 /* Control types for commands */
 
 enum misc_command_type
