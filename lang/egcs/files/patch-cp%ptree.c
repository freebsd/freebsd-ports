--- gcc/cp/ptree.c.orig	1999/08/26 09:29:01	1.1.1.2
+++ gcc/cp/ptree.c	1999/09/19 11:00:01	1.3
@@ -19,7 +19,9 @@
 the Free Software Foundation, 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.  */
 
+/* $from_FreeBSD: src/contrib/gcc/cp/ptree.c,v 1.3 1999/09/19 11:00:01 obrien Exp $ */
 
+
 #include "config.h"
 #include "system.h"
 #include "tree.h"
@@ -46,17 +48,17 @@
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
 
