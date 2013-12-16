--- gold/options.h.orig	2013-12-13 18:39:11.252052912 +0100
+++ gold/options.h	2013-12-13 18:41:04.363051429 +0100
@@ -716,9 +716,9 @@
 	      N_("Output cross reference table"),
 	      N_("Do not output cross reference table"));
 
-  DEFINE_bool(ctors_in_init_array, options::TWO_DASHES, '\0', true,
-	      N_("Use DT_INIT_ARRAY for all constructors (default)"),
-	      N_("Handle constructors as directed by compiler"));
+  DEFINE_bool(ctors_in_init_array, options::TWO_DASHES, '\0', false,
+	      N_("Use DT_INIT_ARRAY for all constructors"),
+	      N_("Handle constructors as directed by compiler (default)"));
 
   DEFINE_bool(define_common, options::TWO_DASHES, 'd', false,
 	      N_("Define common symbols"),
