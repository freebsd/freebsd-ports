--- cp/ptree.c.orig	Wed Jun 28 13:38:11 1995
+++ cp/ptree.c	Mon Mar 20 13:29:12 2000
@@ -46,17 +46,17 @@
   if (DECL_MAIN_VARIANT (node))
     {
       fprintf (file, " decl-main-variant ");
-      fprintf (file, HOST_PTR_PRINTF, DECL_MAIN_VARIANT (node));
+      fprintf (file, HOST_PTR_PRINTF, (void *) DECL_MAIN_VARIANT (node));
     }
   if (DECL_PENDING_INLINE_INFO (node))
     {
       fprintf (file, " pending-inline-info ");
-      fprintf (file, HOST_PTR_PRINTF, DECL_PENDING_INLINE_INFO (node));
+      fprintf (file, HOST_PTR_PRINTF, (void *) DECL_PENDING_INLINE_INFO (node));
     }
   if (DECL_TEMPLATE_INFO (node))
     {
       fprintf (file, " template-info ");
-      fprintf (file, HOST_PTR_PRINTF,  DECL_TEMPLATE_INFO (node));
+      fprintf (file, HOST_PTR_PRINTF, (void *) DECL_TEMPLATE_INFO (node));
     }
 }
 
