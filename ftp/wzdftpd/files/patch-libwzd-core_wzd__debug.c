--- libwzd-core/wzd_debug.c.orig	2023-02-11 11:21:12 UTC
+++ libwzd-core/wzd_debug.c
@@ -318,7 +318,7 @@ int check_context(wzd_context_t * context)
     out_err(LEVEL_CRITICAL,"CRITICAL context      %p\n",context);
     return 1;
   }
-  if (!context->magic == CONTEXT_MAGIC)
+  if (context->magic != CONTEXT_MAGIC)
   {
     out_err(LEVEL_CRITICAL,"CRITICAL context->magic is invalid, context may be corrupted\n");
     return 1;
